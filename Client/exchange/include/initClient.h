#ifndef NETWORKPROGRAM_CHECKINPUT_H
#define NETWORKPROGRAM_CHECKINPUT_H

#include <netinet/in.h>
#include "applicationScreen.h"
/**
 * Hàm này khởi tạo socket kết nối lên server
 * @param address : địa chỉ server
 * @param port : cổng server hoạt động
 * @return trả về socketID
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
