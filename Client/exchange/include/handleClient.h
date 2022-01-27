#ifndef NETWORKPROGRAM_HANDLECLIENT_H
#define NETWORKPROGRAM_HANDLECLIENT_H

#include "structData.h"
#include "applicationScreen.h"
#include "styleScreen.h"
#include "constant.h"

int registerAccount(char *accountName, char *password, int sockFd);

int loginAccount(char *accountName, char *password, int sockFd);

void viewHistory(int sockFd);

void viewListOnlineAccount(int sockFd);

void sendMessage(char *message, int sockFd);

void sendRequestNewGame(char *account, int sockFd);

void sendNextGameStatus(int row, int col, int sockFd);

void handleRecvData(char *dataRecv);

void addFriend(char *account, int sockFd);

void sendMessageAcceptPlay();
#endif
