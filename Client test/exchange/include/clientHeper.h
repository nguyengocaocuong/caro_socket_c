#ifndef NETWORKPROGRAM_CLIENTHEPER_H
#define NETWORKPROGRAM_CLIENTHEPER_H

#include "structData.h"

char *makeSendDataLogin(char *accountName, char *password);

char *makeSendDataMessage(char *message);

char *makeSendDataNewGame(char *account);

char *makeSendDataNextGameStatus(int row, int col);

char *makeSendDataRegister(char *accountName, char *password);

char *makeSendDataRAddFriend(char *accountName);

char *makeSendDataAcceptPlay(char *account);

PersonHistory *separationDataHistory(char *dataHistory, int *size);

PersonHistory *separationDataOnline(char *dataOnline, int *size);

void separationDataCell(char *dataCell, int *row, int *col);

char *separationDataMessage(char *dataMessage);

char *separationDataAddFriend(char *dataRecv);

char *separationDataAcceptPlay(char *dataRecv);
#endif
