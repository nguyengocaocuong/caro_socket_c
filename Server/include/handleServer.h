#ifndef SERVER_HANDLESERVER_H
#define SERVER_HANDLESERVER_H

#include "structData.h"
#include "constant.h"


void handleRecvData(int sockFd);

void updateNewReadFds();

void handleSelect();

void handleAcceptConnect();

void handleRecvDataNewGame(GameStatus *gameStatus, char *recvData, int requestSockFd, int otherSockFd);

char *getIpAddrFromSockAddr(struct sockaddr_in sockAddrIn);

int getPortFromSockAddr(struct sockaddr_in sockAddrIn);

#endif
