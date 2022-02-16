#ifndef SERVER_SERVERHEPER_H
#define SERVER_SERVERHEPER_H

#include "structData.h"
/**
 * Hàm này tạo dữ liệu lịch sử thi đấu để gửi về cho client, khi được yêu cầu xem lịch sử
 * @param sockId : socketID của client yêu cầu xem lịch sử
 * @return : dữ liệu (PREFIX_HISTORY#name1|win|28-10-2000#name2|lost|18-2-2000)
 */
char *makeSendDataHistory(int sockId);
/**
 * Hàm này tạo dữ liệu thông tin các client đang online để gửi về cho client, khi được yêu cầu xem danh sách online
 * @param sockId : socketID của client yêu cầu xem danh sách online
 * @return : dữ liệu (PREFIX_ONLINE#name1#name2#name3)
 */
char *makeSendDataOnlineAccount(int sockId);
/**
 * Hàm này tạo dữ liệu thông báo cho client biết yêu cầu chơi game của họ đã được chấp nhận
 * @param account : tên tài khoản chấp nhận chơi game
 * @return : dữ liệu (PREFIX_ACCEPT_PLAY#account)
 */
char *makeSendDataAcceptPlay(char *account);
/**
 * Hàm này tạo dữ liệu để thông báo cho người chơi biết mình đã thắng và những ô cờ trên nước đi giành chiến thắng
 * @param winIndex : mảng hai chiều lưu trữ các nước đi giành chiến thắng
 * @return : dữ liệu (PREFIX_WIN#1#0#2#0#3#0#4#0#5#0)
 */
char *makeSendDataWinGame(int *winIndex[]);
/**
 * Hàm này tạo dữ liệu để thông báo cho người chơi biết mình đã thua và những ô cờ trên nước đi giành chiến thắng của đối thủ
 * @param winIndex : mảng hai chiều lưu trữ các nước đi giành chiến thắng của đối thủ
 * @return : dữ liệu (PREFIX_LOST#1#0#2#0#3#0#4#0#5#0)
 */
char *makeSendDataLostGame(int *winIndex[]);
/**
 * Hàm này phân tích dữ liệu mà client gửi lên khi đăng ký mới một tài khoản
 * @param recvRegister : dữ liệu nhận dược (PREFIX_REGISTER#account#password)
 * @param account : con trỏ dùng để lưu trữ dữ liệu phân tách được
 */
void separationDataRegister(char *recvRegister, DataAccount *account);
/**
 * Hàm này dùng để phân tách dữ liệu khi một client gửi yêu cầu chơi game đến một client khác
 * @param recvNewGame : dữ liệu nhận được (PREFIX_NEW_GAME#account)
 * @return : account
 */
char *separationDataNewGame(char *recvNewGame);
/**
 * Hàm này tạo dữ liệu để gửi yêu cầu chơi game đến một client
 * @param account : tên của client muốn yêu cầu chơi game
 * @return : dữ liệu (PREFIX_NEW_GAME#account)
 */
char *makeSendDataNewGame(char *account);
/**
 * Phân tách dữ liệu khi một client đồng ý yêu cầu chơi game của một client khác
 * @param recvAcceptPlay : dữ liệu nhận được (PREFIX_ACCEPT_PLAY)
 * @return : account
 */
char *separationDataAcceptPlay(char *recvAcceptPlay);
/**
 *
 * @param recvCell
 * @param row
 * @param col
 */
void separationDataNextGameStatus(char *recvCell, int *row, int *col);
/**
 * Hàm này dùng để phân tách dữ liệu khi một client muốn login
 * @param recvData : dữ liệu nhận được (PREFIX_LOGIN#account#password)
 * @param dataAccount : cấu trúc lưu trữ thông tin tài khoản phân tách được
 */
void separationDataLogin(char *recvData, DataAccount *dataAccount);

/**
 * Hàm này đễ xóa các cấu trúc lưu trữ thông tin của server
 */
void freeServerData();
/**
 * Hàm này có chức năng lấy ra thời gian hiện tại, tạo string thông tin thời gian hiện tại, cần khi ghi lịch sử thi đấu
 * @return : thời gian hiện tại  (28-10-2000)
 */
char *getCurrentTime();
/**
 * Hàm này tạo dữ liệu chứa cell vừa được client chọn
 * @param row
 * @param col
 * @return : dữ liệu (PREFIX_CELL#1#2)
 */
char *makeSendDataNextGameStatus(int row, int col);
#endif
