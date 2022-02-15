#ifndef SERVER_HANDLESERVER_H
#define SERVER_HANDLESERVER_H

#include "structData.h"
#include "constant.h"

/**
 * Hàm này có nhiệm vụ đọc dữ liệu từ socketFd kết nối tới client, phân tích và xử lí dữ liệu nhận được
 * @param sockFd : socketFD được kết nối với client cần đọc data
 */
void handleRecvData(int sockFd);
/**
 * Hàm này cập nhật lại danh sách readFds chứa tất cả các socket kết nối tới server và socket lắng nghe kết nối của server
 */
void updateNewReadFds();
/**
 * Hàm này xử lí hoạt động mỗi khi hàm SELECT nhận được tín hiệu
 */
void handleSelect();
/**
 * Hàm này chập nhận kết nối của một client
 */
void handleAcceptConnect();
/**
 * Hàm này xử việc phân tích data nhận được từ client trong một ván game (trong luồng con xử lí cho ván game)
 * @param gameStatus : cấu trúc data lưu trữ các thông tin của ván game
 * @param recvData : dữ liệu nhận được từ client
 * @param requestSockFd : socket kết nối đến client gửi data lên
 * @param otherSockFd : soket kết nối đến client còn lại trong ván game
 */
void handleRecvDataNewGame(GameStatus *gameStatus, char *recvData, int requestSockFd, int otherSockFd);

/**
 * Hàm này trả về địa chỉ của client
 * @param sockAddrIn : cấu trúc lưu trữ thông tin của client
 * @return : trả về địa chỉ của client
 */
char *getIpAddrFromSockAddr(struct sockaddr_in sockAddrIn);

/**
 * Hàm này có chức năng trả về cổng hoạt động của client
 * @param sockAddrIn : cấu trúc lưu trữ thông tin của client
 * @return : trả về cổng của client hoạt động
 */
int getPortFromSockAddr(struct sockaddr_in sockAddrIn);

#endif
