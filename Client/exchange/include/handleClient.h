#ifndef NETWORKPROGRAM_HANDLECLIENT_H
#define NETWORKPROGRAM_HANDLECLIENT_H

#include "structData.h"
#include "applicationScreen.h"
#include "styleScreen.h"
#include "constant.h"
/**
 *
 * @param accountName
 * @param password
 * @param sockFd
 * @return
 */
int registerAccount(char *accountName, char *password, int sockFd);
/**
 *
 * @param accountName
 * @param password
 * @param sockFd
 * @return
 */
int loginAccount(char *accountName, char *password, int sockFd);
/**
 *
 * @param sockFd
 */
void viewHistory(int sockFd);
/**
 *
 * @param sockFd
 */
void viewListOnlineAccount(int sockFd);
/**
 *
 * @param message
 * @param sockFd
 */
void sendMessage(char *message, int sockFd);
/**
 *
 * @param account
 * @param sockFd
 */
void sendRequestNewGame(char *account, int sockFd);
/**
 *
 * @param row
 * @param col
 * @param sockFd
 */
void sendNextGameStatus(int row, int col, int sockFd);
/**
 *
 * @param dataRecv
 */
void handleRecvData(char *dataRecv);
/**
 *
 */
void sendMessageAcceptPlay();
#endif
