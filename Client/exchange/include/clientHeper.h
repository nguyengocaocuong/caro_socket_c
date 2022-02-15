#ifndef NETWORKPROGRAM_CLIENTHEPER_H
#define NETWORKPROGRAM_CLIENTHEPER_H

#include "structData.h"
/**
 * Hàm này tạo dữ liệu login để gửi lên server
 * @param accountName
 * @param password
 * @return : dữ liệu (PREFIX_LOGIN#account#password)
 */
char *makeSendDataLogin(char *accountName, char *password);
/**
 * Hàm này tạo dữ liệu tin nhắn gửi cho người chơi cùng
 * @param message
 * @return : dữ liệu (PREFIX_MESSAGE#hello)
 */
char *makeSendDataMessage(char *message);
/**
 * Hàm này tạo dữ liệu mà client yêu cầu một client khác chơi game
 * @param account : tài khoản client muốn chơi cùng
 * @return : dữ liệu (PREFIX_NEW_GAME#account)
 */
char *makeSendDataNewGame(char *account);
/**
 * Hàm này tạo dữ liệu chứa cell vừa được client chọn
 * @param row
 * @param col
 * @return : dữ liệu (PREFIX_CELL#1#2)
 */
char *makeSendDataNextGameStatus(int row, int col);
/**
 * hàm này tạo dữ liệu chứa thông tin đăng ký tài khoản
 * @param accountName
 * @param password
 * @return dữ liệu (PREFIX_REGISTER#account#password)
 */
char *makeSendDataRegister(char *accountName, char *password);
/**
 * Hàm này tạo thông điệp đồng ý yêu cầu chơi game của client khác
 * @param account
 * @return : dữ liệu (PREFIX_ACCEPT_PLAY#account)
 */
char *makeSendDataAcceptPlay(char *account);
/**
 * Hàm này có chức năng phân tích thông điệp chứa lịch sử thi đấu nhận từ server
 * @param dataHistory : thông điệp chứa thông tin lịch sử thi đấu nhận từ server (PREFIX_HISTORY#name1|win|28-10-2000#name2|lost|11-1-2001)
 * @param size : nhận số lượng thông điệp
 * @return : Danh sách lịch sử thi đấu
 */
PersonHistory *separationDataHistory(char *dataHistory, int *size);
/**
 * hàm này có chức năng phân tích thông điệp chứa danh sách client online nhận từ server
 * @param dataOnline : thông điệp chứa danh sách client online nhận từ server (PREFIX_ONLINE#name1#name2#name3)
 * @param size : số lượng client online
 * @return : con trỏ chứa danh sách các client online nhận được
 */
PersonHistory *separationDataOnline(char *dataOnline, int *size);
/**
 * Hàm này phân tách thông tin cell mà client khác hoặc server vừa chọn
 * @param dataCell : thông điệp nhận được (PREFIX_CELL#1#2)
 * @param row
 * @param col
 */
void separationDataCell(char *dataCell, int *row, int *col);
/**
 * Hàm này phân tách message nhận được do client khác gửi đến thông qua server
 * @param dataMessage : thông điệp nhận được (PREFIX_MESSAGE#message)
 * @return : message
 */
char *separationDataMessage(char *dataMessage);
/**
 * Hàm này phân tách thông điệp chấp nhận yêu cầu chơi game
 * @param dataRecv : thông điệp nhận được (PREFIX_ACCEPT_PLAY#account)
 * @return : account
 */
char *separationDataAcceptPlay(char *dataRecv);
#endif
