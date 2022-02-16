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

    //Lấy ra prefix
    char *token = strtok(tmp, SEPARATOR);
    if (recvSize <= 0) return;
    if (strcmp(token, PREFIX_CLOSE) == 0) {
        removeBySocketID(sockFd);
        close(sockFd);
        if(tmp != NULL) free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_LOGIN) == 0) {
        DataAccount dataAccount;
        separationDataLogin(recvData, &dataAccount);

        //Nếu không tồn tại tài khoản, hoặc tài khoản đã đăng nhập thì thông báo đăng nhập không thành công
        if (isAccount(dataAccount.account, dataAccount.password) ||
            getBySockName(dataAccount.account) != NULL) {
            send(sockFd, PREFIX_FAIL, MAX_LEN_BUFF, 0);
            if(tmp != NULL) free(tmp);
            return;
        }

        Client *client = (Client *) getBySockID(sockFd);

        //Nếu tài khoản đã đăng nhập thì thông báo đăng nhập không thành công
        if (client->dataClient->status == CLIENT_STATUS_ON) {
            send(sockFd, PREFIX_FAIL, MAX_LEN_BUFF, 0);
            if(tmp != NULL) free(tmp);
            return;
        }

        //Copy thông tin clinet vào cấu trúc lưu trữ thông tin client
        strcpy(client->dataClient->name, dataAccount.account);
        strcpy(client->dataClient->password, dataAccount.password);
        //Đặt lại trạng thái của client
        client->dataClient->status = CLIENT_STATUS_ON;
        send(sockFd, PREFIX_SUCCESS, MAX_LEN_BUFF, 0);
        if(tmp != NULL) free(tmp);
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
        Client *client = (Client *) getBySockID(sockFd);
        strcpy(client->dataClient->name, account.account);
        strcpy(client->dataClient->password, account.password);
        client->dataClient->status = CLIENT_STATUS_ON;
        send(sockFd, PREFIX_SUCCESS, MAX_LEN_BUFF, 0);
        if(data != NULL)free(data);
        return;
    }
    if (strcmp(token, PREFIX_HISTORY) == 0) {
        char *sendData = makeSendDataHistory(sockFd);
        send(sockFd, sendData, MAX_LEN_BUFF, 0);
        if(sendData!= NULL)free(sendData);
        if(tmp != NULL) free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_ONLINE) == 0) {
        printf("get online person\n");
        char *sendData = makeSendDataOnlineAccount(sockFd);
        send(sockFd, sendData, MAX_LEN_BUFF, 0);
       if(tmp != NULL) free(tmp);
        if(sendData != NULL) free(sendData);
        return;
    }
    if (strcmp(token, PREFIX_NEW_GAME) == 0) {
        //Nếu yêu cầu là chơi với máy thì yêu cầu được chấp thuận ngay lập tức
        if (strlen(recvData) <= 10) {
            send(sockFd, PREFIX_PLAY, MAX_LEN_BUFF, 0);
            GameStatus gameStatus;
            gameStatus.client[0] = getBySockID(sockFd);

            //Cập nhật lại trạng thái của client là đang chơi
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

            //tạo luồng xử lý cho ván game
            ret = pthread_create(&pthreadId, &attr, multiModeHandleNewGame, &gameStatus);
            if (ret) {
                printf("pthread_create() error number=%d\n", ret);
                return;
            }
            if(tmp !=NULL)free(tmp);
            return;
        }
        else {
            //Lấy thông tin của đối phương, người được yêu cầu chơi game
            char *account = separationDataNewGame(recvData);
            Client *client = getBySockName(account);
            //Nếu đối phương sẵn sàng cho một ván game, thì gửi yêu cầu đến đối phương
            if (client != NULL || client->dataClient->status != CLIENT_STATUS_NOT_ALREADY) {
                Client *requestClient = getBySockID(sockFd);
                char *sendData = makeSendDataNewGame(requestClient->dataClient->name);
                send(client->dataClient->sockFd, sendData, MAX_LEN_BUFF, 0);
                free(sendData);
            }
            if(account!= NULL)free(account);
        }
        free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_ACCEPT_PLAY) == 0) {
        char *account = separationDataAcceptPlay(recvData);
        Client *client = getBySockName(account);
        if (client == NULL) {
            send(sockFd, PREFIX_FAIL_REQUEST_NEW_GAME, MAX_LEN_BUFF, 0);
            printf("%s\n", PREFIX_FAIL_REQUEST_NEW_GAME);
            return;
        }
        Client *requestClient = getBySockID(sockFd);
        char *sendDataClient = makeSendDataAcceptPlay(requestClient->dataClient->name);

        //Thông báo đến người chơi yêu cầu chơi game của họ đã được đồng ý
        send(sockFd, PREFIX_PLAY, MAX_LEN_BUFF, 0);
        send(client->dataClient->sockFd, sendDataClient, MAX_LEN_BUFF, 0);

        printf("%s\n", PREFIX_PLAY);
        printf("%s\n", sendDataClient);
        char *sendData = makeSendDataNewGame(requestClient->dataClient->name);
        printf("%s\n", sendData);
        send(client->dataClient->sockFd, sendData, MAX_LEN_BUFF, 0);

        //Khởi tạo thông tin của ván game
        GameStatus gameStatus;
        gameStatus.client[0] = client;
        gameStatus.client[1] = requestClient;

        //cập nhật trạng thái của client
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
        //tạo luồng xử lý cho ván game
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
        //Chỉ những client có trạng thái khác với trạng thái CLIENT_STATUS_NOT_ALREADY mới được server lắng nghe, bởi vì các client ở trạng thái này đang ở trong ván game
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
    //Có hai kiểu socket được lắng nghe , là socket để chấp nhận kết nối đến, và các socjket của các client đã kết nối
    for (int i = 0; i < serverData.maxFd; ++i)
        if (FD_ISSET(i, &(serverData.readFds))) {
            //Nếu socket nhận được dữ liệu là socket của server dùng để lắng nghe kết nối
            if (i == serverData.listenFD) handleAcceptConnect();
            //Ngược lại là socket kết nối với client
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
        //Nếu ván game này là ván chơi giữa hai người
        if (gameStatus->isMachine == NOT_MACHINE) {
            gameStatus->gridGame[col][row] = requestSockFd > otherSockFd ? X_ICON : O_ICON;
            int *winIndex[5];
            //Gửi nước đi của client này cho client kia
            send(otherSockFd, recvData, MAX_LEN_BUFF, 0);

            //Kiểm tra trạng thái ván game
            if (checkStatusGame(gameStatus, col, row, winIndex) == GAME_STATUS_WIN) {
                Client *winClient = getBySockID(requestSockFd);
                Client *lostClient = getBySockID(otherSockFd);
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
                if(currentTime != NULL)free(currentTime);
                if(history != NULL) free(history);
                if(sendLost != NULL) free(sendLost);
                if(sendWin != NULL) free(sendWin);
            }
            free(tmp);
            return;
        }
        else {
            int *winIndex[5];
            gameStatus->gridGame[col][row] =  X_ICON;
            if (checkStatusGame(gameStatus, col, row, winIndex) == GAME_STATUS_WIN) {
                Client *winClient = getBySockID(requestSockFd);
                char *history = (char *) calloc(1, MAX_LEN_BUFF);
                char *currentTime = getCurrentTime();
                char *sendWin = makeSendDataWinGame(winIndex);
                char *sendLost = makeSendDataLostGame(winIndex);
                sprintf(history, "%s#%s#%s#%s", winClient->dataClient->name, "May", "win",
                        currentTime);
                writeFileHistory(history);
                addList(createDataHistory(history), TAG_HISTORY);
                free(history);
                history = (char *) calloc(1, MAX_LEN_BUFF);
                sprintf(history, "%s#%s#%s#%s", "May", winClient->dataClient->name, "lost",
                        currentTime);
                writeFileHistory(history);
                addList(createDataHistory(history), TAG_HISTORY);
                send(requestSockFd, sendWin, MAX_LEN_BUFF, 0);
                printf("%s\n", sendWin);
                if(currentTime != NULL)free(currentTime);
                if(history != NULL) free(history);
                if(sendLost != NULL) free(sendLost);
                if(sendWin != NULL) free(sendWin);
                return;
            }
//            printf("Den luot server\n");
            getNextCell(gameStatus->gridGame,&col,&row);
            char *sendCell = makeSendDataNextGameStatus(row,col);
            gameStatus->gridGame[col][row] = O_ICON;
//            printf("%s\n",sendCell);
            send(requestSockFd, sendCell, MAX_LEN_BUFF, 0);
            free(sendCell);
            free(tmp);
            return;
        }
    }
    if (strcmp(token, PREFIX_CLOSE) == 0) {
        removeBySocketID(requestSockFd);
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