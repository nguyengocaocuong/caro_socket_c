#ifndef SERVER_HANDLEDATABASE_H
#define SERVER_HANDLEDATABASE_H

#include <stdio.h>
#include "constant.h"
#include "structData.h"

FILE *openFile(const char *fileName, const char *mode);

void readAllFileDataBase();

void readFileHistory();

void readFileAccount();

void writeFileHistory(char *data);

void writeFileAccount(char *data);

#endif

