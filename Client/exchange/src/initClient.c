#include <arpa/inet.h>
#include <stdlib.h>

#include "initClient.h"
#include "clientError.h"


int initSocket(const char *address, const int port) {
    memset(&(userData.serverAddr), 0, sizeof(userData.serverAddr));
    if ((userData.sockFd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        return ERROR_CREATE_SOCKET;

    userData.serverAddr.sin_port = htons(port);
    userData.serverAddr.sin_addr.s_addr = inet_addr(address);

//run bug
//    userData.serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
//    userData.serverAddr.sin_port = htons(5501);
    userData.serverAddr.sin_family = AF_INET;

    if (connect(userData.sockFd, (struct sockaddr *) &(userData.serverAddr), sizeof(userData.serverAddr)))
        return ERROR_CONNECT_FAIL;

    return userData.sockFd;
}

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