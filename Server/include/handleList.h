#ifndef SERVER_HANDLELIST_H
#define SERVER_HANDLELIST_H

#include "structData.h"
/**
 * Hàm này để thêm một phần tử mới vào danh sách tương ứng
 * @param data : dữ liệu cần thêm vào danh sách
 * @param tag : là dữ liệu dùng để cho biết cần thêm phần tử này vào danh sách nào
 * TAG_CLIENT | TAG_HISTORY | TAG_ACCOUNT
 */
void addList(void *data, int tag);
/**
 * Hàm này dùng để xóa một danh sách
 * @param tag : là dữ liệu dùng để cho biết cần xóa danh sách nào
 * TAG_CLIENT | TAG_HISTORY | TAG_ACCOUNT
 */
void freeList(int tag);

/**
 * Xóa một phần tử ra khỏi danh sách thông qua socketID của client
 * @param sockID : socketID của phần tử cần xóa
 */
void removeBySocketID(int sockID);
/**
 * Lấy một phần tử từ danh sách thông qua socketID của client
 * @param sockId : socket của phần tử muốn lấy
 * @return trả về con trỏ đến phần từ muốn lấy, hoặc NULL nếu không tìm thấy
 */
void *getBySockID(int sockId);
/**
 * Lấy một phần tử từ danh sách thông qua tên của client
 * @param account : tên tài khoản
 * @return : con trỏ đến phần tử cần lấy, hoặc NULL nếu không tìm thấy
 */
void *getBySockName(char *account);
/**
 * Kiểm tra xem tài khoản có tồn tại hay không
 * @param account : tên đăng nhập
 * @param password : mật khẩu
 * @return : 0 _ nếu tài khoản tồn tại | 1 _ nếu tài khoản không tồn tại
 */
int isAccount(const char *account, char *password);
/**
 * Tạo một bản sao của một phần từ
 * @param ins : phần tử cần tạo bản sao
 * @param tag : là dữ liệu cho biết kiểu của phần tử
 * @return : con trỏ đến bản sao của phần tử
 */
void *cloneIns(void *ins, int tag);
/**
 * Hàm này đặt lại trạng thái của môt client
 * @param sockFd : socketID của phần tử cần đặt lại trạng thái
 * @param status :  trạng thái cần thiết lập
 * CLIENT_STATUS_OF | CLIENT_STATUS_ON | CLIENT_STATUS_NOT_ALREADY
 */
void setStatus(int sockFd, int status);

#endif
