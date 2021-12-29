#ifndef SERVER_HANDLESERVER_H
#define SERVER_HANDLESERVER_H

#include "structData.h"
#include "constant.h"


void handleRecvData(int sockFd, ServerData *serverData);

void updateNewReadFds(ServerData *serverData);

void handleSelect(ServerData *serverData);

void handleAcceptConnect(ServerData *serverData);

void handleRecvDataNewGame(GameStatus *gameStatus, char *recvData, int requestSockFd, int otherSockFd);

char *getIpAddrFromSockAddr(struct sockaddr_in sockAddrIn);

int getPortFromSockAddr(struct sockaddr_in sockAddrIn);

#endif
