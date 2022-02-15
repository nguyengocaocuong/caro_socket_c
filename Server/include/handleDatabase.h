#ifndef SERVER_HANDLEDATABASE_H
#define SERVER_HANDLEDATABASE_H

#include <stdio.h>
#include "constant.h"
#include "structData.h"
/**
 * Hàm này dùng đề mở file theo chế độ
 * @param fileName : tên file, đường dẫn file cần mở
 * @param mode : chế độ mở file
 * @return : con trỏ đến file đã được mở
 */
FILE *openFile(const char *fileName, const char *mode);
/**
 * Hàm này gọi các hàm đọc file bên dưới để đọc tất cả các file lưu trữ, khi khởi chạy server
 */
void readAllFileDataBase();
/**
 * Hàm này dùng đề đọc file lịch sử thi đấu
 */
void readFileHistory();
/**
 * Hàm này dùng đề đọc file tài khoản
 */
void readFileAccount();
/**
 * Hàm này dùng để ghi lịch sử thi đấu của một trận đấu
 * @param data : dữ liệu ghi vào file
 */
void writeFileHistory(char *data);
/**
 * Hàm này dùng để ghi thông tin của một tài khoản mới
 * @param data : là dữ liệu thông tin của tài khoản mới được đăng kí, cần ghi vào file
 */
void writeFileAccount(char *data);

#endif

