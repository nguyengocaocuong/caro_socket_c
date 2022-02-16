#ifndef NETWORKPROGRAM_HANDLETHREAD_H
#define NETWORKPROGRAM_HANDLETHREAD_H


#include "clientError.h"
#include "constant.h"
#include "handleLogicGameScreen.h"
/**
 * hàm này xử việc nhận thông không đồng bộ từ server
 * @return
 */
static void *multiModeHandle() {
    printf("Enter thread :\n");
    int selectStatus;
    char recvData[MAX_LEN_BUFF];
    int recvSize;
    fd_set readFds;
    struct timeval timeval;
    timeval.tv_sec = 10;
    timeval.tv_usec = 0;
    while (1) {
        FD_ZERO(&readFds);
        FD_SET(userData.sockFd, &readFds);
        selectStatus = select(userData.sockFd + 1, &readFds, NULL, NULL, NULL);
        if (selectStatus == -1) {
            printf("Break thread :\n");
            pthread_exit(NULL);
        } else if (selectStatus == 0) {
            printf("Het thoi gian cho!\n");
            printf("Break thread :\n");
            pthread_exit(NULL);
        } else {
            recvSize = recv(userData.sockFd, recvData, MAX_LEN_BUFF, 0);
            recvData[recvSize] = 0;
            char *dataRecv = (char *) calloc(1, MAX_LEN_BUFF);
            strcpy(dataRecv, recvData);
            if (recvSize > 0)
                handleRecvData(dataRecv);
            if(dataRecv!= NULL ) free(dataRecv);
        }
    }
}

#endif
