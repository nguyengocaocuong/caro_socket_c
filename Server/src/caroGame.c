#include <stdio.h>
#include <malloc.h>
#include "caroGame.h"
#include "constant.h"

int checkStatusGame(GameStatus *gameStatus, int row, int col, int *winIndex[]) {
    int win[5][2];
    int index = 0;
//    printf("==================\n");
//    printf("New Status Game:\n");
//    for (int i = 0; i < 15; ++i) {
//        for (int j = 0; j < 15; ++j) {
//            printf("[%c]", gameStatus->gridGame[i][j] == 0 ? '_' : '0' + gameStatus->gridGame[i][j]);
//        }
//        printf("\n");
//    }
//    printf("==================\n");
//    printf("Check game : row(%d) col(%d)\n", row, col);
    int cl = col;
    int rl = row;
    win[index][0] = row;
    win[index++][1] = col;

    // check ngang
    int left = 0;
    int right = 1;
    while (cl < 14 && gameStatus->gridGame[row][col] == gameStatus->gridGame[rl][++cl]) {
        win[index][0] = rl;
        win[index++][1] = cl;
        right++;
        if (right == 5) {
            printf("WIN : ");
            for (int i = 0; i < 5; ++i) {
                printf("[%d][%d] | ", win[i][0], win[i][1]);
                int *cell = (int *) calloc(2, sizeof(int));
                cell[0] = win[i][0];
                cell[1] = win[i][1];
                winIndex[i] = cell;
            }

            printf("\n");
            return GAME_STATUS_WIN;
        }
    }
    cl = col;
    while (cl > -1 && gameStatus->gridGame[row][col] == gameStatus->gridGame[rl][--cl]) {
        win[index][0] = rl;
        win[index++][1] = cl;
        left++;
        if (right + left == 5) {
            printf("WIN : ");
            for (int i = 0; i < 5; ++i) {
                printf("[%d][%d] | ", win[i][0], win[i][1]);
                int *cell = (int *) calloc(2, sizeof(int));
                cell[0] = win[i][0];
                cell[1] = win[i][1];
                winIndex[i] = cell;
            }
            printf("\n");
            return GAME_STATUS_WIN;
        }
    }

    //check doc
    index = 1;
    int down = 1;
    int up = 0;
    rl = row;
    cl = col;
    while (rl < 14 && gameStatus->gridGame[row][col] == gameStatus->gridGame[++rl][cl]) {
        win[index][0] = rl;
        win[index++][1] = cl;
        down++;
        if (down == 5) {
            printf("WIN : ");
            for (int i = 0; i < 5; ++i) {
                printf("[%d][%d] | ", win[i][0], win[i][1]);
                int *cell = (int *) calloc(2, sizeof(int));
                cell[0] = win[i][0];
                cell[1] = win[i][1];
                winIndex[i] = cell;
            }
            printf("\n");
            return GAME_STATUS_WIN;
        }
    }
    rl = row;
    while (cl > -1 && gameStatus->gridGame[row][col] == gameStatus->gridGame[--rl][cl]) {
        win[index][0] = rl;
        win[index++][1] = cl;
        up++;
        if (up + down == 5) {
            printf("WIN : ");
            for (int i = 0; i < 5; ++i) {
                printf("[%d][%d] | ", win[i][0], win[i][1]);
                int *cell = (int *) calloc(2, sizeof(int));
                cell[0] = win[i][0];
                cell[1] = win[i][1];
                winIndex[i] = cell;
            }
            printf("\n");
            return GAME_STATUS_WIN;
        }
    }

    //check cheo trai
    index = 1;

    int left_top = 1;
    int right_down = 0;
    rl = row;
    cl = col;
    while (rl > -1 && col > -1 && gameStatus->gridGame[row][col] == gameStatus->gridGame[--rl][--cl]) {
        win[index][0] = rl;
        win[index++][1] = cl;
        left_top++;
        if (left_top == 5) {
            printf("WIN : ");
            for (int i = 0; i < 5; ++i) {
                printf("[%d][%d] | ", win[i][0], win[i][1]);
                int *cell = (int *) calloc(2, sizeof(int));
                cell[0] = win[i][0];
                cell[1] = win[i][1];
                winIndex[i] = cell;
            }
            printf("\n");
            return GAME_STATUS_WIN;
        }
    }
    rl = row;
    cl = col;
    while (rl < 14 && cl < 14 && gameStatus->gridGame[row][col] == gameStatus->gridGame[++rl][++cl]) {
        right_down++;
        win[index][0] = rl;
        win[index++][1] = cl;
        if (left_top + right_down == 5) {
            printf("WIN : ");
            for (int i = 0; i < 5; ++i) {
                printf("[%d][%d] | ", win[i][0], win[i][1]);
                int *cell = (int *) calloc(2, sizeof(int));
                cell[0] = win[i][0];
                cell[1] = win[i][1];
                winIndex[i] = cell;
            }
            printf("\n");
            return GAME_STATUS_WIN;
        }
    }

    //check cheo phai
    index = 1;
    int right_top = 1;
    int left_down = 0;
    rl = row;
    cl = col;
    while (cl < 14 && rl > -1 && gameStatus->gridGame[row][col] == gameStatus->gridGame[--rl][++cl]) {
        right_top++;
        win[index][0] = rl;
        win[index++][1] = cl;
        if (right_top == 5) {
            printf("WIN : ");
            for (int i = 0; i < 5; ++i) {
                printf("[%d][%d] | ", win[i][0], win[i][1]);
                int *cell = (int *) calloc(2, sizeof(int));
                cell[0] = win[i][0];
                cell[1] = win[i][1];
                winIndex[i] = cell;
            }
            printf("\n");
            return GAME_STATUS_WIN;
        }
    }
    rl = row;
    cl = col;
    while (rl < 14 && cl > -1 && gameStatus->gridGame[row][col] == gameStatus->gridGame[++rl][--cl]) {
        left_down++;
        win[index][0] = rl;
        win[index++][1] = cl;
        if (right_top + left_down == 5) {
            printf("WIN : ");
            for (int i = 0; i < 5; ++i) {
                printf("[%d][%d] | ", win[i][0], win[i][1]);
                int *cell = (int *) calloc(2, sizeof(int));
                cell[0] = win[i][0];
                cell[1] = win[i][1];
                winIndex[i] = cell;
            }
            printf("\n");
            return GAME_STATUS_WIN;
        }
    }

    return GAME_STATUS_NEXT_CELL;
}

