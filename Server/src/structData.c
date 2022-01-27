#include <stdlib.h>
#include <string.h>

#include "structData.h"
#include "constant.h"

DataClient *createDataClient(int sockFd, struct sockaddr_in clientAddr) {
    DataClient *dataClient = (DataClient *) calloc(1, sizeof(DataClient));
    dataClient->sockFd = sockFd;
    dataClient->clientAddr = clientAddr;
    dataClient->status = CLIENT_STATUS_OF;
    return dataClient;
}

DataHistory *createDataHistory(char *data) {
    char *token = NULL;
    DataHistory *dataHistory = (DataHistory *) calloc(1, sizeof(DataHistory));
    token = strtok(data, SEPARATOR);
    strcpy(dataHistory->firstAccount, token);
    token = strtok(NULL, SEPARATOR);
    strcpy(dataHistory->secondAccount, token);
    token = strtok(NULL, SEPARATOR);
    strcpy(dataHistory->result, token);
    token = strtok(NULL, SEPARATOR);
    strcpy(dataHistory->date, token);
    return dataHistory;
}

DataFriend *createDataFriend(char *data) {
    char *token = NULL;
    DataFriend *dataFriend = (DataFriend *) calloc(1, sizeof(DataFriend));
    token = strtok(data, SEPARATOR);
    strcpy(dataFriend->firstAccount, token);
    token = strtok(NULL, SEPARATOR);
    strcpy(dataFriend->secondAccount, token);
    return dataFriend;
}

DataAccount *createDataAccount(char *data) {
    char *token = NULL;
    DataAccount *dataAccount = (DataAccount *) calloc(1, sizeof(DataAccount));
    token = strtok(data, SEPARATOR);
    strcpy(dataAccount->account, token);
    token = strtok(NULL, SEPARATOR);
    strcpy(dataAccount->password, token);
    return dataAccount;
}