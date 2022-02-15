#ifndef NETWORKPROGRAM_CHECKINPUT_H
#define NETWORKPROGRAM_CHECKINPUT_H

#include <netinet/in.h>
#include "applicationScreen.h"
/**
 *
 * @param address
 * @param port
 * @return
 */
int initSocket(const char *address, int port);
/**
 *
 * @param sockAddrIn
 * @return
 */
char *getIpAddrFromSockAddr(struct sockaddr_in sockAddrIn);
/**
 *
 * @param sockAddrIn
 * @return
 */
int getPortFromSockAddr(struct sockaddr_in sockAddrIn);

#endif
