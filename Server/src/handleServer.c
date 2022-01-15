#include <unistd.h>

#include "caroGame.h"
#include "handleDatabase.h"
#include "serverHeper.h"
#include "handleList.h"
#include "handleThread.h"

char *getIpAddrFromSockAddr(const struct sockaddr_in sockAddrIn) {
    char *str = NULL;
    str = (char *) realloc(str, INET_ADDRSTRLEN);
    struct in_addr ipAddr = sockAddrIn.sin_addr;
    inet_ntop(AF_INET, &ipAddr, str, INET_ADDRSTRLEN);
    return str;
}

int getPortFromSockAddr(const struct sockaddr_in sockAddrIn) {
    return ntohs(sockAddrIn.sin_port);
}

void handleRecvData(int sockFd, ServerData *serverData) {
    char recvData[MAX_LEN_BUFF];
    int recvSize;
    recvSize = recv(sockFd, recvData, MAX_LEN_BUFF, 0);
    recvData[recvSize] = 0;
    printf("%s\n", recvData);
    char *tmp = (char *) calloc(1, MAX_LEN_BUFF);
    strcpy(tmp, recvData);
    char *token = strtok(tmp, SEPARATOR);

    if (strcmp(token, PREFIX_CLOSE) == 0) {
        removeBySocketID(serverData, sockFd, TAG_CLIENT);
        close(sockFd);
        free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_LOGIN) == 0) {
        DataAccount dataAccount;
        separationDataLogin(recvData, &dataAccount);
        if (isAccount(serverData, dataAccount.account, dataAccount.password)) {
            send(sockFd, PREFIX_FAIL, MAX_LEN_BUFF, 0);
            free(tmp);
            return;
        }
        Client *client = (Client *) getBySockID(serverData, sockFd, TAG_CLIENT);
        strcpy(client->dataClient->name, dataAccount.account);
        strcpy(client->dataClient->password, dataAccount.password);
        send(sockFd, PREFIX_SUCCESS, MAX_LEN_BUFF, 0);
        free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_REGISTER) == 0) {
        DataAccount account;
        separationDataRegister(recvData, &account);
        char *data = (char *) calloc(1, MAX_LEN_BUFF);
        strcat(data, account.account);
        strcat(data, SEPARATOR);
        strcat(data, account.password);

        // kiem tra tai khoan
        printf("%s\n", data);
        writeFileAccount(serverData, data);
        addList(serverData, createDataAccount(data), TAG_ACCOUNT);
        Client *client = (Client *) getBySockID(serverData, sockFd, TAG_CLIENT);
        strcpy(client->dataClient->name, account.account);
        strcpy(client->dataClient->password, account.password);
        send(sockFd, PREFIX_SUCCESS, MAX_LEN_BUFF, 0);
        free(data);
        return;
    }
    if (strcmp(token, PREFIX_HISTORY) == 0) {
        char *sendData = makeSendDataHistory(serverData, sockFd);
        send(sockFd, sendData, MAX_LEN_BUFF, 0);
        free(sendData);
        free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_ONLINE) == 0) {
        char *sendData = makeSendDataOnlineAccount(serverData, sockFd);
        send(sockFd, sendData, MAX_LEN_BUFF, 0);
        free(tmp);
        free(sendData);
        return;
    }
    if (strcmp(token, PREFIX_NEW_GAME) == 0) {
        char *account = separationDataNewGame(recvData);
        Client *client = getBySockName(serverData, account, TAG_CLIENT);
        Client *requestClient = getBySockID(serverData, sockFd, TAG_CLIENT);
        char *sendData = makeSendDataNewGame(requestClient->dataClient->name);
        send(client->dataClient->sockFd, sendData, MAX_LEN_BUFF, 0);
        free(sendData);
        free(account);
        free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_ACCEPT_PLAY) == 0) {
        char *account = separationDataAcceptPlay(recvData);
        Client *client = getBySockName(serverData, account, TAG_CLIENT);
        if (client == NULL) {
            send(sockFd, PREFIX_FAIL_REQUEST_NEW_GAME, MAX_LEN_BUFF, 0);
            printf("%s\n", PREFIX_FAIL_REQUEST_NEW_GAME);
            return;
        }
        Client *requestClient = getBySockID(serverData, sockFd, TAG_CLIENT);
        char *sendDataClient = makeSendDataAcceptPlay(requestClient->dataClient->name);

        send(sockFd, PREFIX_PLAY, MAX_LEN_BUFF, 0);
        send(client->dataClient->sockFd, sendDataClient, MAX_LEN_BUFF, 0);

        printf("%s\n", PREFIX_PLAY);
        printf("%s\n", sendDataClient);
        char *sendData = makeSendDataNewGame(requestClient->dataClient->name);
        printf("%s\n", sendData);
        send(client->dataClient->sockFd, sendData, MAX_LEN_BUFF, 0);

        GameStatus gameStatus;
        gameStatus.client[0] = client;
        gameStatus.client[1] =requestClient;
        gameStatus.client[0]->dataClient->status = CLIENT_STATUS_NOT_ALREADY;
        gameStatus.client[1]->dataClient->status = CLIENT_STATUS_NOT_ALREADY;
        gameStatus.serverData = &serverData;
        gameStatus.isMachine = NOT_MACHINE;
//        removeBySocketID(serverData, client->dataClient->sockFd, TAG_CLIENT);
//        removeBySocketID(serverData, requestClient->dataClient->sockFd, TAG_CLIENT);
        for (int i = 0; i < 15; ++i)
            for (int j = 0; j < 15; ++j)
                gameStatus.gridGame[i][j] = 0;
        int ret;

        struct sched_param schedParam;
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_getschedparam(&attr, &schedParam);
        schedParam.sched_priority = 50;

        pthread_attr_setschedpolicy(&attr, SCHED_RR);
        pthread_attr_setschedparam(&attr, &schedParam);

        pthread_t pthreadId;
        ret = pthread_create(&pthreadId, &attr, multiModeHandleNewGame, &gameStatus);
        if (ret) {
            printf("pthread_create() error number=%d\n", ret);
            return;
        }
        free(sendData);
        free(account);
        free(sendDataClient);
        free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_ADD_FRIEND) == 0) {
        free(tmp);
        return;
    }
}

void updateNewReadFds(ServerData *serverData) {
    int maxFd = serverData->listenFD;
    int tmpSockFd;
    FD_ZERO(&(serverData->readFds));
    FD_SET(serverData->listenFD, &(serverData->readFds));
    Client *tmp = serverData->client;
    serverData->maxFd = 0;
    while (tmp != NULL) {
        if (tmp->dataClient->status == CLIENT_STATUS_ON) {
            tmpSockFd = tmp->dataClient->sockFd;
            FD_SET(tmpSockFd, &(serverData->readFds));
            maxFd = maxFd > tmpSockFd ? maxFd : tmpSockFd;
        }
        tmp = tmp->nextClient;
    }
    serverData->maxFd = maxFd + 1;
}

void handleAcceptConnect(ServerData *serverData) {
    int cnnFd;
    struct sockaddr_in clientAddr;
    socklen_t sockAddrLen;
    memset(&clientAddr, 0, sizeof clientAddr);
    cnnFd = accept(serverData->listenFD, (struct sockaddr *) &clientAddr, &sockAddrLen);
    DataClient *dataClient = createDataClient(cnnFd, clientAddr);
    addList(serverData, dataClient, TAG_CLIENT);
}

void handleSelect(ServerData *serverData) {
    for (int i = 0; i < serverData->maxFd; ++i)
        if (FD_ISSET(i, &(serverData->readFds))) {
            if (i == serverData->listenFD) handleAcceptConnect(serverData);
            else handleRecvData(i, serverData);
        }
}

void handleRecvDataNewGame(GameStatus *gameStatus, char *recvData, int requestSockFd, int otherSockFd) {
    char *tmp = (char *) calloc(1, MAX_LEN_BUFF);
    strcpy(tmp, recvData);
    char *token = strtok(tmp, SEPARATOR);
    if (strcmp(token, PREFIX_MESSAGE) == 0) {
        send(otherSockFd, recvData, MAX_LEN_BUFF, 0);
        free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_CELL) == 0) {
        int row = recvData[6] - '0';
        int col = recvData[8] - '0';
        gameStatus->gridGame[col][row] = requestSockFd > otherSockFd ? X_ICON : O_ICON;
        int *winIndex[5];
        if (checkStatusGame(gameStatus, col, row, winIndex) == GAME_STATUS_WIN) {
            char *sendWin = makeSendDataWinGame(winIndex);
            char *sendLost = makeSendDataLostGame(winIndex);
            send(otherSockFd, recvData, MAX_LEN_BUFF, 0);
            send(requestSockFd, sendWin, MAX_LEN_BUFF, 0);
            send(otherSockFd, sendLost, MAX_LEN_BUFF, 0);

            Client *winClient = getBySockID(gameStatus->serverData, requestSockFd, TAG_CLIENT);
            Client *lostClient = getBySockID(gameStatus->serverData, otherSockFd, TAG_CLIENT);
            char *history = (char *) calloc(1, MAX_LEN_BUFF);
            char *currentTime = getCurrentTime();
            sprintf(history, "%s#%s#%s#%s", winClient->dataClient->name, lostClient->dataClient->name, "win",
                    currentTime);
            writeFileHistory(gameStatus->serverData, history);
            free(history);
            history = (char *) calloc(1, MAX_LEN_BUFF);
            sprintf(history, "%s#%s#%s#%s", lostClient->dataClient->name, winClient->dataClient->name, "lost",
                    currentTime);
            writeFileHistory(gameStatus->serverData, history);
            printf("\n");
            printf("%s\n", sendWin);
            printf("%s\n", sendLost);
            free(currentTime);
            free(history);
            free(tmp);
            free(sendLost);
            free(sendWin);
            return;
        }
        if (gameStatus->isMachine = IS_MACHINE) {

        } else {
        }
        send(otherSockFd, recvData, MAX_LEN_BUFF, 0);
        free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_CLOSE) == 0) {
        removeBySocketID(gameStatus->serverData, requestSockFd, TAG_CLIENT);
        pthread_exit(NULL);
    }
    if (strcmp(token, PREFIX_END_GAME) == 0) {
//        gameStatus->client[0]->dataClient->status = CLIENT_STATUS_ON;
//        gameStatus->client[1]->dataClient->status = CLIENT_STATUS_ON;
//
//        DataClient *dataClient = createDataClient(gameStatus->client[0]->dataClient->sockFd, gameStatus->client[0]->dataClient->clientAddr);
//        DataClient *dataClient1 = createDataClient(gameStatus->client[1]->dataClient->sockFd, gameStatus->client[1]->dataClient->clientAddr);
//        addList(&serverData, dataClient, TAG_CLIENT);
//        addList(&serverData, dataClient1, TAG_CLIENT);
//
//        serverData.test = 1;
        pthread_exit(NULL);
    }
}