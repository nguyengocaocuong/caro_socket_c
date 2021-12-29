#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "serverHeper.h"
#include "initServer.h"
#include "constant.h"
#include "handleList.h"

void writeLog(const Client *client, char *sendData,char *tag){
    printf("%5s%25s : %s\n",tag,client->dataClient->name,sendData);
}

char *makeSendDataNextGameStatus(int row, int col) {

    return NULL;
}

char *makeSendDataHistory(ServerData *serverData, int sockId) {
    char *sendData = (char *) calloc(1, MAX_LEN_BUFF);
    strcat(sendData, PREFIX_HISTORY);
    History *tmp = serverData->history;
    Client *currentClient = (Client *) getBySockID(serverData, sockId, TAG_CLIENT);

    while (tmp != NULL) {
        strcat(sendData, SEPARATOR);
        if (strcmp(tmp->dataHistory->firstAccount, currentClient->dataClient->name) == 0)
            strcat(sendData, tmp->dataHistory->secondAccount);
        else
            strcat(sendData, tmp->dataHistory->firstAccount);
        strcat(sendData, SEPARATOR_HISTORY);
        strcat(sendData, tmp->dataHistory->result);
        strcat(sendData, SEPARATOR_HISTORY);
        strcat(sendData, tmp->dataHistory->date);
        tmp = tmp->nextHistory;
    }
    return sendData;
}

char *makeSendDataOnlineAccount(ServerData *serverData, int sockId) {
    Client *currentClient = getBySockID(serverData, sockId, TAG_CLIENT);
    char *sendData = (char *) calloc(1, MAX_LEN_BUFF);
    strcat(sendData, PREFIX_ONLINE);
    Client *tmp = serverData->client;
    while (tmp != NULL) {
        if (strlen(tmp->dataClient->name) == 0 || strcmp(tmp->dataClient->name, currentClient->dataClient->name) == 0) {
            tmp = tmp->nextClient;
            continue;
        }
        strcat(sendData, SEPARATOR);
        strcat(sendData, tmp->dataClient->name);
        tmp = tmp->nextClient;
    }
    return sendData;
}

char *makeSendDataAcceptPlay(char *account) {
    char *sendData = (char *) calloc(1, MAX_LEN_BUFF);
    strcat(sendData,PREFIX_ACCEPT_PLAY);
    strcat(sendData,SEPARATOR);
    strcat(sendData,account);
    return sendData;
}

char *makeSendDataNewGame(char *account) {
    char *sendData = (char *) calloc(1, MAX_LEN_BUFF);
    strcat(sendData, PREFIX_NEW_GAME);
    strcat(sendData, SEPARATOR);
    strcat(sendData, account);
    return sendData;
}

void separationDataLogin(char *recvData, DataAccount *dataAccount) {
    char *token = strtok(recvData, SEPARATOR);
    token = strtok(NULL, SEPARATOR);
    strcpy(dataAccount->account, token);
    token = strtok(NULL, SEPARATOR);
    strcpy(dataAccount->password, token);
}

char *separationDataNewGame(char *recvNewGame) {
    char *account = (char *) calloc(1, 30);
    char *token = strtok(recvNewGame, SEPARATOR);
    token = strtok(NULL, SEPARATOR);
    strcpy(account, token);
    return account;
}

char *separationDataAcceptPlay(char *recvAcceptPlay) {
    char *account = (char *) calloc(1, 30);
    char *token = strtok(recvAcceptPlay, SEPARATOR);
    token = strtok(NULL, SEPARATOR);
    strcpy(account, token);
    return account;
}

void separationDataRegister(char *recvRegister,DataAccount *account) {
    char *token = strtok(recvRegister,SEPARATOR);
    token= strtok(NULL,SEPARATOR);
    strcpy(account->account,token);
    token = strtok(NULL, SEPARATOR);
    strcpy(account->password, token);
}

void separationDataNextGameStatus(char *recvCell, int *row, int *col) {

}