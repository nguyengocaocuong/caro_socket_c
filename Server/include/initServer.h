#ifndef SERVER_INITSERVER_H
#define SERVER_INITSERVER_H

#include "structData.h"
#include "caroGame.h"

/**
 * Hàm này có chức năng khởi tạo server, tạo socket để lắng nghe kết nối từ client
 * @param port : cổng chạy server
 * @return : 0  _ nếu khởi taọ thành công
 */
int initServer(char *port);

#endif
