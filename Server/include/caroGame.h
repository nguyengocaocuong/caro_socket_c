#ifndef SERVER_CAROGAME_H
#define SERVER_CAROGAME_H

#include "structData.h"
/**
 * Hàm này kiểm tra trạng thái của ván game
 * @param gameStatus : cấu trúc lưu trữ thông tin của ván game
 * @param row : chỉ số hàng vừa được chọn
 * @param col : chỉ số cột vừa được chọn
 * @param windIndex : mảng lưu trữ các nước đi dẫn đến thắng hoặc thua, nếu ván game kết thúc
 * @return : trạng thái của ván game GAME_STATUS_WIN | GAME_STATUS_NEXT_CELL
 */
int checkStatusGame(GameStatus *gameStatus, int row, int col, int *windIndex[]);

/**
 *
 * @param matrix : ma trận, mỗi cell có thể nhận 3 giá trị, 0 : chưa được chọn, 1: người thứ nhất chọn, 2: người thứ hai chọn
 * @param currentCell : là giá trị vừa được chọn, ví dụ giá trị vừa được chọn là 1: tương úng người chơi vừa đi, bây h hàm này tìm ra vị trí tiếp theo mà máy đi, tức là tìm ô để điền số 2
 * @param row : chỉ số hàng tìm được
 * @param col : chỉ số cột tìm được
 */
void getNextCell(int matrix[15][15], int *row, int *col);

#endif