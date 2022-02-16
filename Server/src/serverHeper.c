#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "serverHeper.h"
#include "constant.h"
#include "handleList.h"

//void writeLog(const Client *client, char *sendData, char *tag) {
//    printf("%5s%25s : %s\n", tag, client->dataClient->name, sendData);
//}


char *makeSendDataHistory(int sockId) {
    char *sendData = (char *) calloc(1, MAX_LEN_BUFF);
    strcat(sendData, PREFIX_HISTORY);
    History *tmp = serverData.history;
    Client *currentClient = (Client *) getBySockID(sockId);

    while (tmp != NULL) {
        if (strcmp(tmp->dataHistory->firstAccount, currentClient->dataClient->name) == 0) {
            strcat(sendData, SEPARATOR);
            strcat(sendData, tmp->dataHistory->secondAccount);
            strcat(sendData, SEPARATOR_HISTORY);
            strcat(sendData, tmp->dataHistory->result);
            strcat(sendData, SEPARATOR_HISTORY);
            strcat(sendData, tmp->dataHistory->date);
        }
        tmp = tmp->nextHistory;
    }
    return sendData;
}

char *makeSendDataOnlineAccount(int sockId) {
    Client *currentClient = getBySockID(sockId);
    char *sendData = (char *) calloc(1, MAX_LEN_BUFF);
    strcat(sendData, PREFIX_ONLINE);
    Client *tmp = serverData.client;
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
    strcat(sendData, PREFIX_ACCEPT_PLAY);
    strcat(sendData, SEPARATOR);
    strcat(sendData, account);
    return sendData;
}

char *makeSendDataWinGame(int *winIndex[]) {
    char *sendData = (char *) calloc(1, MAX_LEN_BUFF);
    strcat(sendData, PREFIX_WIN);
    strcat(sendData, SEPARATOR);
    sendData[5] = (char) (winIndex[0][0] + '0');
    sendData[6] = '#';
    sendData[7] = (char) (winIndex[0][1] + '0');

    sendData[8] = '#';

    sendData[9] = (char) (winIndex[1][0] + '0');
    sendData[10] = '#';
    sendData[11] = (char) (winIndex[1][1] + '0');

    sendData[12] = '#';

    sendData[13] = (char) (winIndex[2][0] + '0');
    sendData[14] = '#';
    sendData[15] = (char) (winIndex[2][1] + '0');

    sendData[16] = '#';

    sendData[17] = (char) (winIndex[3][0] + '0');
    sendData[18] = '#';
    sendData[19] = (char) (winIndex[3][1] + '0');

    sendData[20] = '#';

    sendData[21] = (char) (winIndex[4][0] + '0');
    sendData[22] = '#';
    sendData[23] = (char) (winIndex[4][1] + '0');
    sendData[24] = 0;
    return sendData;
}

char *makeSendDataLostGame(int *winIndex[]) {
    char *sendData = (char *) calloc(1, MAX_LEN_BUFF);
    strcat(sendData, PREFIX_LOST);
    strcat(sendData, SEPARATOR);
    sendData[6] = (char) (winIndex[0][0] + '0');
    sendData[7] = '#';
    sendData[8] = (char) (winIndex[0][1] + '0');

    sendData[9] = '#';

    sendData[10] = (char) (winIndex[1][0] + '0');
    sendData[11] = '#';
    sendData[12] = (char) (winIndex[1][1] + '0');

    sendData[13] = '#';

    sendData[14] = (char) (winIndex[2][0] + '0');
    sendData[15] = '#';
    sendData[16] = (char) (winIndex[2][1] + '0');

    sendData[17] = '#';

    sendData[18] = (char) (winIndex[3][0] + '0');
    sendData[19] = '#';
    sendData[20] = (char) (winIndex[3][1] + '0');

    sendData[21] = '#';

    sendData[22] = (char) (winIndex[4][0] + '0');
    sendData[23] = '#';
    sendData[24] = (char) (winIndex[4][1] + '0');
    sendData[25] = 0;
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

void separationDataRegister(char *recvRegister, DataAccount *account) {
    char *token = strtok(recvRegister, SEPARATOR);
    token = strtok(NULL, SEPARATOR);
    strcpy(account->account, token);
    token = strtok(NULL, SEPARATOR);
    strcpy(account->password, token);
}

void separationDataNextGameStatus(char *recvCell, int *row, int *col) {

}

void freeServerData(ServerData *serverData) {
    if (serverData == NULL) return;
    if (serverData->account != NULL) {
        Account *tmp = serverData->account;
        Account *p = NULL;
        while (tmp != NULL) {
            p = tmp;
            tmp = p->nextAccount;
            free(p->dataAccount);
            free(p);
        }
        serverData->account = NULL;
    }
    if (serverData->friend != NULL) {
        Friend *tmp = serverData->friend;
        Friend *p = NULL;
        while (tmp != NULL) {
            p = tmp;
            tmp = p->nextFriend;
            free(p->dataFriend);
            free(p);
        }
        serverData->friend = NULL;
    }
    if (serverData->history != NULL) {
        History *tmp = serverData->history;
        History *p = NULL;
        while (tmp != NULL) {
            p = tmp;
            tmp = tmp->nextHistory;
            free(p->dataHistory);
            free(p);
        }
        serverData->history = NULL;
    }
    if (serverData->client != NULL) {
        Client *tmp = serverData->client;
        Client *p = NULL;
        while (tmp != NULL) {
            p = tmp;
            tmp = tmp->nextClient;
            free(p->dataClient);
            free(p);
        }
        serverData->client = NULL;
    }
}

char *getCurrentTime() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char *currentTime = (char *) calloc(1, MAX_LEN_BUFF);
    sprintf(currentTime, "%d-%d-%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    return currentTime;
}

char *makeSendDataNextGameStatus(int row, int col) {
    char *sendBuff = (char *) calloc(1, MAX_LEN_BUFF);
    strcat(sendBuff, PREFIX_CELL);
    strcat(sendBuff, SEPARATOR);
    sendBuff[6] = row + '0';
    strcat(sendBuff, SEPARATOR);
    sendBuff[8] =  col + '0';
    sendBuff[9] = 0;
    printf("send : %s\n",sendBuff);
    return sendBuff;
}

