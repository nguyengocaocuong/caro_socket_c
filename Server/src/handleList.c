#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "handleList.h"
#include "constant.h"

void addList(void *data, int tag) {
    void *root = NULL;
    switch (tag) {
        case TAG_CLIENT:
            root = (Client *) calloc(1, sizeof(Client));
            ((Client *) root)->dataClient = (DataClient *) data;
            ((Client *) root)->nextClient = NULL;
            if (serverData.client == NULL) {
                serverData.client = ((Client *) root);
            } else {
                Client *tmp = serverData.client;
                while (tmp->nextClient != NULL)
                    tmp = tmp->nextClient;
                tmp->nextClient = ((Client *) root);
            }
            break;
        case TAG_ACCOUNT:
            root = (Account *) calloc(1, sizeof(Account));
            ((Account *) root)->dataAccount = (DataAccount *) data;
            ((Account *) root)->nextAccount = NULL;
            if (serverData.account == NULL) {
                serverData.account = ((Account *) root);
            } else {
                Account *tmp = serverData.account;
                while (tmp->nextAccount != NULL)
                    tmp = tmp->nextAccount;
                tmp->nextAccount = ((Account *) root);
            }
            break;
        case TAG_FRIEND:
            root = (Friend *) calloc(1, sizeof(Friend));
            ((Friend *) root)->dataFriend = (DataFriend *) data;
            ((Friend *) root)->nextFriend = NULL;
            if (serverData.friend == NULL) {
                serverData.friend = ((Friend *) root);
            } else {
                Friend *tmp = serverData.friend;
                while (tmp->nextFriend != NULL)
                    tmp = tmp->nextFriend;
                tmp->nextFriend = ((Friend *) root);
            }
            break;
        case TAG_HISTORY:
            root = (History *) calloc(1, sizeof(History));
            ((History *) root)->dataHistory = (DataHistory *) data;
            ((History *) root)->nextHistory = NULL;
            if (serverData.history == NULL) {
                serverData.history = ((History *) root);
            } else {
                History *tmp = serverData.history;
                while (tmp->nextHistory != NULL)
                    tmp = tmp->nextHistory;
                tmp->nextHistory = ((History *) root);
            }
            break;
        default:
            return;
    }
}

void freeList(int tag) {
    switch (tag) {
        case TAG_CLIENT:
            if (serverData.client == NULL) return;
            Client *tmp = serverData.client;
            while (serverData.client != NULL) {
                serverData.client = serverData.client->nextClient;
                free(tmp->dataClient);
                free(tmp);
                tmp = serverData.client;
            }
            break;
        case TAG_ACCOUNT:

            break;
        case TAG_FRIEND:

            break;
        case TAG_HISTORY:

            break;
        default:
            return;
    }

}

void removeBySocketID(int sockID) {
    void *tmp = NULL;
    void *preTmp = NULL;
    if (serverData.client == NULL) return;
    tmp = (Client *) serverData.client;
    preTmp = (Client *) serverData.client;
    while (tmp != NULL) {
        if (((Client *) tmp)->dataClient->sockFd == sockID) {
            if ((Client *) tmp == (Client *) preTmp) {
                preTmp = ((Client *) preTmp)->nextClient;
                serverData.client = preTmp;
                free(((Client *) tmp)->dataClient);
                free((Client *)tmp);
                break;
            } else {
                ((Client *) preTmp)->nextClient = ((Client *) tmp)->nextClient;
                free(((Client *) tmp)->dataClient);
                free((Client *) tmp);
                break;
            }
        }
        preTmp = tmp;
        tmp = ((Client *) tmp)->nextClient;
    }
}

void *cloneIns(void *ins, int tag) {
    if (tag == TAG_CLIENT) {
        DataClient *dataClient = NULL;
        dataClient = createDataClient(((Client *) ins)->dataClient->sockFd, ((Client *) ins)->dataClient->clientAddr);
        strcpy(dataClient->name, ((Client *) ins)->dataClient->name);
        Client *newIns = (Client *) calloc(1, sizeof(Client *));
        newIns->nextClient = NULL;
        newIns->dataClient = dataClient;
        return newIns;
    }
    return NULL;
}

void *getBySockID(int sockId) {
    if (serverData.client == NULL) return NULL;
    Client *tmp = serverData.client;
    while (tmp != NULL) {
        if (tmp->dataClient->sockFd == sockId)
            return tmp;
        tmp = tmp->nextClient;
    }
    return NULL;
}

void setStatus(int sockId, int status){
    if (serverData.client == NULL) return ;
    Client *tmp =  getBySockID(sockId);
    if(tmp != NULL)
        tmp->dataClient->status = CLIENT_STATUS_ON;
}
void *getBySockName(char *account) {
    if (serverData.client == NULL) return NULL;
    Client *tmp = serverData.client;
    while (tmp != NULL) {
        if (strcmp(tmp->dataClient->name, account) == 0)
            return tmp;
        tmp = tmp->nextClient;
    }
    return NULL;
}

int isAccount(const char *account, char *password) {
    if (serverData.account == NULL) return 1;
    Account *tmp = serverData.account;
    while (tmp != NULL) {
        if (strcmp(tmp->dataAccount->account, account) == 0 && strcmp(tmp->dataAccount->password, password) == 0)
            return 0;
        tmp = tmp->nextAccount;
    }
    return 1;
}