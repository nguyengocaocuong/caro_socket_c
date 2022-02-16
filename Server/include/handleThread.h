#ifndef SERVER_HANDLETHREAD_H
#define SERVER_HANDLETHREAD_H

#include <stdio.h>
#include <sys/select.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#include "handleServer.h"
#include "structData.h"
#include "constant.h"

/**
 * Hàm này là hàm xử lí nó như hàm main trong luồng con, xử lý một ván game
 * @param argv : tham số truyền vào cho hàm này, khi khởi tạo luồng, nó chính là thông tin trạng thái của ván game
 * @return
 */
static void *multiModeHandleNewGame(void *argv) {
    int selectStatus;
    char recvData[MAX_LEN_BUFF];
    int recvSize;
    GameStatus *gameStatus = (GameStatus *) argv;
    fd_set readFds;
    struct timeval timeval;
    timeval.tv_sec = 10;
    timeval.tv_usec = 0;
    int sock1 = gameStatus->client[0]->dataClient->sockFd, sock2;
    if (gameStatus->isMachine == NOT_MACHINE)
        sock2 = gameStatus->client[1]->dataClient->sockFd;
    int maxFd;
    maxFd = gameStatus->isMachine == NOT_MACHINE ? sock1 > sock2 ? sock1 + 1 : sock2 + 1 : sock1 + 1;
    while (1) {
        FD_ZERO(&readFds);
        FD_SET(sock1, &readFds);
        if (gameStatus->isMachine == NOT_MACHINE)
            FD_SET(sock2, &readFds);
        selectStatus = select(maxFd, &readFds, NULL, NULL, NULL);
        if (selectStatus == -1) {
            printf("Break thread :\n");
            pthread_exit(NULL);
        } else if (selectStatus == 0) {
            printf("Het thoi gian cho!\n");
            pthread_exit(NULL);
        } else {
            if (FD_ISSET(sock1, &readFds)) {
                recvSize = recv(sock1, recvData, MAX_LEN_BUFF, 0);
                recvData[recvSize] = 0;
                if (recvSize > 0) {
                    printf("Client1 : %s\n", recvData);
                    char *dataRecv = (char *) calloc(1, MAX_LEN_BUFF);
                    strcpy(dataRecv, recvData);
                    if (dataRecv == NULL || strlen(dataRecv) <= 0) continue;
                    handleRecvDataNewGame(gameStatus, dataRecv, sock1, sock2);
                    if (dataRecv != NULL) free(dataRecv);
                }
            }
            if (gameStatus->isMachine == NOT_MACHINE && FD_ISSET(sock2, &readFds)) {
                recvSize = recv(sock2, recvData, MAX_LEN_BUFF, 0);
                recvData[recvSize] = 0;
                if (recvSize > 0) {
                    printf("Client2 : %s\n", recvData);
                    char *dataRecv = (char *) calloc(1, MAX_LEN_BUFF);
                    strcpy(dataRecv, recvData);
                    if (dataRecv == NULL || strlen(dataRecv) <= 0) continue;
                    handleRecvDataNewGame(gameStatus, dataRecv, sock2, sock1);
                    if (dataRecv != NULL) free(dataRecv);
                }
            }
        }
    }
}

#endif
