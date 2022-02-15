#ifndef NETWORKPROGRAM_HANDLECLIENT_H
#define NETWORKPROGRAM_HANDLECLIENT_H

#include "structData.h"
#include "applicationScreen.h"
#include "styleScreen.h"
#include "constant.h"
/**
 * Gàm này thực hiện gửi thông điệp đăng ký tài khoản lên server
 * @param accountName
 * @param password
 * @param sockFd
 * @return 0 _ đăng ký thành công | 1 _ đăng ký thất bại
 */
int registerAccount(char *accountName, char *password, int sockFd);
/**
 * Hàm này thực hiện gửi thông điệp login lên server
 * @param accountName
 * @param password
 * @param sockFd
 * @return 0 _ đăng nhập thành công | 1 _ đăng nhập thất bại
 */
int loginAccount(char *accountName, char *password, int sockFd);
/**
 * Hàm này thực hiện yêu cầu xem lịch sử thi đấu
 * @param sockFd
 */
void viewHistory(int sockFd);
/**
 * Hàm này thực hiện yêu cầu xem danh sách người chơi online
 * @param sockFd
 */
void viewListOnlineAccount(int sockFd);
/**
 * Hàm này gửi tín nhán cho client khác
 * @param message
 * @param sockFd
 */
void sendMessage(char *message, int sockFd);
/**
 * Hàm này thực hiện gửi yêu cầu chơi game
 * @param account
 * @param sockFd
 */
void sendRequestNewGame(char *account, int sockFd);
/**
 * Hàm này gửi vị trí client vừa chọn
 * @param row
 * @param col
 * @param sockFd
 */
void sendNextGameStatus(int row, int col, int sockFd);
/**
 * Hàm này xử lý thông điệp nhận được từ server
 * @param dataRecv
 */
void handleRecvData(char *dataRecv);
/**
 * Hàm này thực hiện đồng ý yêu cầu client khác chơi game
 */
void sendMessageAcceptPlay();
#endif
