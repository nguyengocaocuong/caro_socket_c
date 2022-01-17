#ifndef SERVER_SERVERHEPER_H
#define SERVER_SERVERHEPER_H

#include "structData.h"

char *makeSendDataHistory(int sockId);

char *makeSendDataOnlineAccount(int sockId);

char *makeSendDataAcceptPlay(char *account);

char *makeSendDataWinGame(int *winIndex[]);

char *makeSendDataLostGame(int *winIndex[]);

void separationDataRegister(char *recvRegister, DataAccount *account);

char *separationDataNewGame(char *recvNewGame);

char *makeSendDataNewGame(char *account);

char *separationDataAcceptPlay(char *recvAcceptPlay);

void separationDataNextGameStatus(char *recvCell, int *row, int *col);

void writeLog(const Client *client, char *sendData, char *tag);

void separationDataLogin(char *recvData, DataAccount *dataAccount);

char *makeSendDataNextGameStatus(int row, int col);

void freeServerData();

char *getCurrentTime();

#endif
