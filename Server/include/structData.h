#ifndef SERVER_STRUCTDATA_H
#define SERVER_STRUCTDATA_H

#include <arpa/inet.h>

typedef struct {
    int sockFd;
    struct sockaddr_in clientAddr;
    char name[30];
    char password[30];
    int status;
} DataClient;

typedef struct {
    char account[30];
    char password[30];
} DataAccount;

typedef struct {
    char firstAccount[30];
    char secondAccount[30];
} DataFriend;

typedef struct {
    char firstAccount[30];
    char secondAccount[30];
    char result[10];
    char date[20];
} DataHistory;

typedef struct _client {
    struct _client *nextClient;
    DataClient *dataClient;
} Client;

typedef struct _friend {
    struct _friend *nextFriend;
    DataFriend *dataFriend;
} Friend;

typedef struct _account {
    struct _account *nextAccount;
    DataAccount *dataAccount;
} Account;

typedef struct _history {
    struct _history *nextHistory;
    DataHistory *dataHistory;
} History;

typedef struct {
    Client *client;
    Account *account;
    Friend *friend;
    History *history;
    struct sockaddr_in serverAddr;
    int listenFD;
    fd_set readFds;
    int maxFd;
} ServerData;

typedef struct {
    Client *client[2];
    int gridGame[15][15];
    int status;
    int nextCell;
    int isMachine;
    int test;
} GameStatus;


DataClient *createDataClient(int sockFd, struct sockaddr_in clientAddr);

DataHistory *createDataHistory(char *data);

DataAccount *createDataAccount(char *data);


ServerData serverData;
#endif
