#ifndef SERVER_HANDLEDATABASE_H
#define SERVER_HANDLEDATABASE_H

#include <stdio.h>
#include "constant.h"
#include "structData.h"

FILE *openFile(const char *fileName, const char *mode);

void readAllFileDataBase();

void readFileHistory();

void readFileFriend();

void readFileAccount();

void writeFileHistory(char *data);

void writeFileFriend();

void writeFileAccount(char *data);

#endif

