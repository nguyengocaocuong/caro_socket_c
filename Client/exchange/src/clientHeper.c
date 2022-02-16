#include <stdlib.h>
#include <string.h>

#include "constant.h"
#include "clientHeper.h"

char *makeSendDataLogin(char *accountName, char *password) {
    char *sendBuff = (char *) calloc(1, MAX_LEN_BUFF);
    strcat(sendBuff, PREFIX_LOGIN);
    strcat(sendBuff, SEPARATOR);
    strcat(sendBuff, accountName);
    strcat(sendBuff, SEPARATOR);
    strcat(sendBuff, password);
    if(sendBuff[strlen(sendBuff)] == '\n') sendBuff[strlen(sendBuff)] = 0;
    return sendBuff;
}

char *makeSendDataRegister(char *accountName, char *password) {
    char *sendBuff = (char *) calloc(1, MAX_LEN_BUFF);
    strcat(sendBuff, PREFIX_REGISTER);
    strcat(sendBuff, SEPARATOR);
    strcat(sendBuff, accountName);
    strcat(sendBuff, SEPARATOR);
    strcat(sendBuff, password);
    if(sendBuff[strlen(sendBuff)] == '\n') sendBuff[strlen(sendBuff)] = 0;
    return sendBuff;
}


char* makeSendDataAcceptPlay(char *account) {
    char *sendBuff = (char*) calloc(1,MAX_LEN_BUFF);
    strcat(sendBuff,PREFIX_ACCEPT_PLAY);
    strcat(sendBuff,SEPARATOR);
    strcat(sendBuff,account);
    return sendBuff;
}

char *makeSendDataMessage(char *message) {
    char *sendBuff = (char *) calloc(1, MAX_LEN_BUFF);
    strcat(sendBuff, PREFIX_MESSAGE);
    strcat(sendBuff, SEPARATOR);
    strcat(sendBuff, message);
    return sendBuff;
}

char *makeSendDataNewGame(char *account) {
    char *sendBuff = (char *) calloc(1, MAX_LEN_BUFF);
    strcat(sendBuff, PREFIX_NEW_GAME);
    strcat(sendBuff, SEPARATOR);
    strcat(sendBuff, account);
    return sendBuff;
}

char *makeSendDataNextGameStatus(int row, int col) {
    char *sendBuff = (char *) calloc(1, MAX_LEN_BUFF);
    strcat(sendBuff, PREFIX_CELL);
    strcat(sendBuff, SEPARATOR);
    sendBuff[6] = (char) row;
    strcat(sendBuff, SEPARATOR);
    sendBuff[8] = (char) col;
    sendBuff[9] = 0;
    return sendBuff;
}

PersonHistory *separationDataHistory(char *dataHistory, int *size) {
    int total = 0;
    char *token = strtok(dataHistory, SEPARATOR);

    if (token == NULL) return NULL;
    PersonHistory *personHistory = NULL;
    while (token != NULL) {
        if (total == 0) personHistory = (PersonHistory *) calloc(1, sizeof(PersonHistory));
        else personHistory = (PersonHistory *) realloc(personHistory, (total + 1) * sizeof(PersonHistory));

        token = strtok(NULL, SEPARATOR_HISTORY);
        if (token == NULL) break;
        strcpy(personHistory[total].name, token);

        token = strtok(NULL, SEPARATOR_HISTORY);
        if (token == NULL) break;

        strcpy(personHistory[total].result, token);

        token = strtok(NULL, SEPARATOR_HISTORY);
        if (token == NULL) break;

        strcpy(personHistory[total].date, token);
        total++;
    }
    *size = total;
    return personHistory;
}

PersonHistory *separationDataOnline(char *dataOnline, int *size) {
    int total = 0;
    char *token = strtok(dataOnline, SEPARATOR);

    if (token == NULL) return NULL;
    PersonHistory *personOnline = NULL;
    while (token != NULL) {
        if (total == 0) personOnline = (PersonHistory *) calloc(total + 1, sizeof(PersonHistory));
        else personOnline = (PersonHistory *) realloc(personOnline, (total + 1) * sizeof(PersonHistory));
        if (token == NULL) break;
        token = strtok(NULL, SEPARATOR);
        if (token == NULL) break;
        strcpy(personOnline[total].name, token);
        total++;
    }
    *size = total;
    return personOnline;
}

void separationDataCell(char *dataCell, int *row, int *col) {
    *row = dataCell[6] - '0';
    *col = dataCell[8] - '0';
}

char *separationDataMessage(char *dataMessage) {
    char *token = strtok(dataMessage, SEPARATOR);
    token = strtok(NULL, SEPARATOR);
    char *message = (char *) calloc(1, sizeof(token));
    strcpy(message, token);
    return message;
}


char *separationDataAcceptPlay(char *dataRecv){
    char *token = strtok(dataRecv, SEPARATOR);
    token = strtok(NULL, SEPARATOR);
    char *account = (char *) calloc(1, MAX_LEN_BUFF);
    strcpy(account, token);
    return account;
}