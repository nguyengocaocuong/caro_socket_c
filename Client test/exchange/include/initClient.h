#ifndef NETWORKPROGRAM_CHECKINPUT_H
#define NETWORKPROGRAM_CHECKINPUT_H

#include <netinet/in.h>
#include "applicationScreen.h"

int initSocket(const char *address, int port, UserData *userData);

char *getIpAddrFromSockAddr(struct sockaddr_in sockAddrIn);

int getPortFromSockAddr(struct sockaddr_in sockAddrIn);

#endif
