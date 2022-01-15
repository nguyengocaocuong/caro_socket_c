#ifndef SERVER_HANDLELIST_H
#define SERVER_HANDLELIST_H

#include "structData.h"

void addList(ServerData *serverData, void *data, int tag);

void freeList(ServerData *serverData, int tag);

void removeByAccount(ServerData *serverData, char *account, int tag);

void removeBySocketID(ServerData *serverData, int sockID, int tag);

int isByAccount(const ServerData *serverData, char *name, int tag);

int isBySocketId(const ServerData *serverData, int sockID, int tag);

int isClientAlreadyForNewGameByAccount(const ServerData *serverData, char *account);

int isClientAlreadyForNewGameBySockID(const ServerData *serverData, char *account);

void *getBySockID(ServerData *serverData, int sockId, int tag);

void *getBySockName(ServerData *serverData, char *account, int tag);

int isAccount(const ServerData *serverData, char *account, char *password);

void *cloneIns(void *ins, int tag);
#endif
