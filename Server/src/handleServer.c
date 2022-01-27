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

void handleRecvData(int sockFd) {
    char recvData[MAX_LEN_BUFF];
    int recvSize;
    recvSize = recv(sockFd, recvData, MAX_LEN_BUFF, 0);
    recvData[recvSize] = 0;
    printf("%s\n", recvData);
    char *tmp = (char *) calloc(1, MAX_LEN_BUFF);
    strcpy(tmp, recvData);
    char *token = strtok(tmp, SEPARATOR);
    if (recvSize <= 0) return;
    if (strcmp(token, PREFIX_CLOSE) == 0) {
        removeBySocketID(sockFd, TAG_CLIENT);
        close(sockFd);
        free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_LOGIN) == 0) {
        DataAccount dataAccount;
        separationDataLogin(recvData, &dataAccount);
        if (isAccount(dataAccount.account, dataAccount.password) ||
            getBySockName(dataAccount.account, TAG_CLIENT) != NULL) {
            send(sockFd, PREFIX_FAIL, MAX_LEN_BUFF, 0);
            free(tmp);
            return;
        }
        Client *client = (Client *) getBySockID(sockFd, TAG_CLIENT);
        if (client->dataClient->status == CLIENT_STATUS_ON) {
            send(sockFd, PREFIX_FAIL, MAX_LEN_BUFF, 0);
            free(tmp);
            return;
        }
        strcpy(client->dataClient->name, dataAccount.account);
        strcpy(client->dataClient->password, dataAccount.password);
        client->dataClient->status = CLIENT_STATUS_ON;
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
        writeFileAccount(data);
        addList(createDataAccount(data), TAG_ACCOUNT);
        Client *client = (Client *) getBySockID(sockFd, TAG_CLIENT);
        strcpy(client->dataClient->name, account.account);
        strcpy(client->dataClient->password, account.password);
        send(sockFd, PREFIX_SUCCESS, MAX_LEN_BUFF, 0);
        free(data);
        return;
    }
    if (strcmp(token, PREFIX_HISTORY) == 0) {
        char *sendData = makeSendDataHistory(sockFd);
        send(sockFd, sendData, MAX_LEN_BUFF, 0);
        free(sendData);
        free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_ONLINE) == 0) {
        char *sendData = makeSendDataOnlineAccount(sockFd);
        send(sockFd, sendData, MAX_LEN_BUFF, 0);
        free(tmp);
        free(sendData);
        return;
    }
    if (strcmp(token, PREFIX_NEW_GAME) == 0) {
        if (strlen(recvData) <= 10) {
            send(sockFd, PREFIX_PLAY, MAX_LEN_BUFF, 0);
            GameStatus gameStatus;
            gameStatus.client[0] = getBySockID(sockFd, TAG_CLIENT);
            gameStatus.client[0]->dataClient->status = CLIENT_STATUS_NOT_ALREADY;
            gameStatus.isMachine = IS_MACHINE;
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
            free(tmp);
            return;
        } else {
            char *account = separationDataNewGame(recvData);
            Client *client = getBySockName(account, TAG_CLIENT);
            if (client != NULL) {
                Client *requestClient = getBySockID(sockFd, TAG_CLIENT);
                char *sendData = makeSendDataNewGame(requestClient->dataClient->name);
                send(client->dataClient->sockFd, sendData, MAX_LEN_BUFF, 0);
                free(sendData);
                free(account);
            }
        }
        free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_ACCEPT_PLAY) == 0) {
        char *account = separationDataAcceptPlay(recvData);
        Client *client = getBySockName(account, TAG_CLIENT);
        if (client == NULL) {
            send(sockFd, PREFIX_FAIL_REQUEST_NEW_GAME, MAX_LEN_BUFF, 0);
            printf("%s\n", PREFIX_FAIL_REQUEST_NEW_GAME);
            return;
        }
        Client *requestClient = getBySockID(sockFd, TAG_CLIENT);
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
        gameStatus.client[1] = requestClient;
        gameStatus.client[0]->dataClient->status = CLIENT_STATUS_NOT_ALREADY;
        gameStatus.client[1]->dataClient->status = CLIENT_STATUS_NOT_ALREADY;
        gameStatus.isMachine = NOT_MACHINE;

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

}

void updateNewReadFds() {
    int maxFd = serverData.listenFD;
    int tmpSockFd;
    FD_ZERO(&(serverData.readFds));
    FD_SET(serverData.listenFD, &(serverData.readFds));
    Client *tmp = serverData.client;

    serverData.maxFd = serverData.listenFD;
    while (tmp != NULL) {
        if (tmp->dataClient->status != CLIENT_STATUS_NOT_ALREADY) {
            tmpSockFd = tmp->dataClient->sockFd;
            FD_SET(tmpSockFd, &(serverData.readFds));
            maxFd = maxFd > tmpSockFd ? maxFd : tmpSockFd;
        }
        tmp = tmp->nextClient;
    }
    serverData.maxFd = maxFd + 1;
}

void handleAcceptConnect() {
    int cnnFd;
    struct sockaddr_in clientAddr;
    socklen_t sockAddrLen;
    memset(&clientAddr, 0, sizeof clientAddr);
    cnnFd = accept(serverData.listenFD, (struct sockaddr *) &clientAddr, &sockAddrLen);
    DataClient *dataClient = createDataClient(cnnFd, clientAddr);
    addList(dataClient, TAG_CLIENT);
}

void handleSelect() {
    for (int i = 0; i < serverData.maxFd; ++i)
        if (FD_ISSET(i, &(serverData.readFds))) {
            if (i == serverData.listenFD) handleAcceptConnect();
            else handleRecvData(i);
        }
}

void handleRecvDataNewGame(GameStatus *gameStatus, char *recvData, int requestSockFd, int otherSockFd) {
    char *tmp = (char *) calloc(1, MAX_LEN_BUFF);
    strcpy(tmp, recvData);
    char *token = strtok(tmp, SEPARATOR);
    if (strcmp(token, PREFIX_MESSAGE) == 0) {
        if (gameStatus->isMachine == NOT_MACHINE)
            send(otherSockFd, recvData, MAX_LEN_BUFF, 0);
        free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_CELL) == 0) {
        int row = recvData[6] - '0';
        int col = recvData[8] - '0';
        if (gameStatus->isMachine == NOT_MACHINE) {
            gameStatus->gridGame[col][row] = requestSockFd > otherSockFd ? X_ICON : O_ICON;
            int *winIndex[5];

            send(otherSockFd, recvData, MAX_LEN_BUFF, 0);

            if (checkStatusGame(gameStatus, col, row, winIndex) == GAME_STATUS_WIN) {
                Client *winClient = getBySockID(requestSockFd, TAG_CLIENT);
                Client *lostClient = getBySockID(otherSockFd, TAG_CLIENT);
                char *history = (char *) calloc(1, MAX_LEN_BUFF);
                char *currentTime = getCurrentTime();
                char *sendWin = makeSendDataWinGame(winIndex);
                char *sendLost = makeSendDataLostGame(winIndex);
                sprintf(history, "%s#%s#%s#%s", winClient->dataClient->name, lostClient->dataClient->name, "win",
                        currentTime);
                writeFileHistory(history);
                addList(createDataHistory(history), TAG_HISTORY);
                free(history);
                history = (char *) calloc(1, MAX_LEN_BUFF);
                sprintf(history, "%s#%s#%s#%s", lostClient->dataClient->name, winClient->dataClient->name, "lost",
                        currentTime);
                writeFileHistory(history);
                addList(createDataHistory(history), TAG_HISTORY);
                printf("\n");
                send(requestSockFd, sendWin, MAX_LEN_BUFF, 0);
                send(otherSockFd, sendLost, MAX_LEN_BUFF, 0);
                printf("%s\n", sendWin);
                printf("%s\n", sendLost);
                free(currentTime);
                free(history);
                free(sendLost);
                free(sendWin);
            }
            free(tmp);
            return;
        } else {
            printf("Den luot server\n");
            free(tmp);
            return;
        }
    }
    if (strcmp(token, PREFIX_CLOSE) == 0) {
        removeBySocketID(requestSockFd, TAG_CLIENT);
        pthread_exit(NULL);
    }
    if (strcmp(token, PREFIX_END_GAME) == 0) {
        if (gameStatus->isMachine != IS_MACHINE)
            send(otherSockFd, PREFIX_END_GAME, MAX_LEN_BUFF, 0);
        setStatus(requestSockFd, CLIENT_STATUS_ON);
        setStatus(otherSockFd, CLIENT_STATUS_ON);

        pthread_exit(NULL);
    }
}