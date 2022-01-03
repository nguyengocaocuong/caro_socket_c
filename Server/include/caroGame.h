#ifndef SERVER_CAROGAME_H
#define SERVER_CAROGAME_H

#include "structData.h"

int checkStatusGame(GameStatus *gameStatus, int row, int col,int *windIndex[]);

void getNextCell(int matrix[15][15],int *row, int *col);
#endif