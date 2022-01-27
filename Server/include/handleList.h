#ifndef SERVER_HANDLELIST_H
#define SERVER_HANDLELIST_H

#include "structData.h"

void addList(void *data, int tag);

void freeList(int tag);

void removeByAccount(char *account, int tag);

void removeBySocketID(int sockID, int tag);

int isByAccount(const char *name, int tag);

int isBySocketId(int sockID, int tag);

int isClientAlreadyForNewGameByAccount(const char *account);

int isClientAlreadyForNewGameBySockID(const char *account);

void *getBySockID(int sockId, int tag);

void *getBySockName(char *account, int tag);

int isAccount(const char *account, char *password);

void *cloneIns(void *ins, int tag);

void setStatus(int sockFd, int status);

#endif
