#ifndef NETWORKPROGRAM_CLIENTHEPER_H
#define NETWORKPROGRAM_CLIENTHEPER_H

#include "structData.h"
/**
 * Hàm này tạo dữ liệu login để gửi lên server
 * @param accountName
 * @param password
 * @return : dữ liệu (PREFIX_LOGIN#account#password)
 */
char *makeSendDataLogin(char *accountName, char *password);
/**
 * Hàm này tạo dữ liệu tin nhắn gửi cho người chơi cùng
 * @param message
 * @return : dữ liệu (PREFIX_MESSAGE#hello)
 */
char *makeSendDataMessage(char *message);
/**
 *
 * @param account
 * @return
 */
char *makeSendDataNewGame(char *account);
/**
 *
 * @param row
 * @param col
 * @return
 */
char *makeSendDataNextGameStatus(int row, int col);
/**
 *
 * @param accountName
 * @param password
 * @return
 */
char *makeSendDataRegister(char *accountName, char *password);
/**
 *
 * @param account
 * @return
 */
char *makeSendDataAcceptPlay(char *account);
/**
 *
 * @param dataHistory
 * @param size
 * @return
 */
PersonHistory *separationDataHistory(char *dataHistory, int *size);
/**
 *
 * @param dataOnline
 * @param size
 * @return
 */
PersonHistory *separationDataOnline(char *dataOnline, int *size);
/**
 *
 * @param dataCell
 * @param row
 * @param col
 */
void separationDataCell(char *dataCell, int *row, int *col);
/**
 *
 * @param dataMessage
 * @return
 */
char *separationDataMessage(char *dataMessage);
/**
 *
 * @param dataRecv
 * @return
 */
char *separationDataAddFriend(char *dataRecv);
/**
 *
 * @param dataRecv
 * @return
 */
char *separationDataAcceptPlay(char *dataRecv);
#endif
