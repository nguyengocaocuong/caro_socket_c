#ifndef SERVER_HANDLEDATABASE_H
#define SERVER_HANDLEDATABASE_H

#include <stdio.h>
#include "constant.h"
#include "structData.h"

FILE *openFile(const char *fileName, const char *mode);

void readAllFileDataBase(ServerData *serverData);

void readFileHistory(ServerData *serverData);

void readFileFriend(ServerData *serverData);

void readFileAccount(ServerData *serverData);

void writeFileHistory(ServerData *serverData,char *data);

void writeFileFriend(ServerData *serverData);

void writeFileAccount(ServerData *serverData,char *data);

#endif

