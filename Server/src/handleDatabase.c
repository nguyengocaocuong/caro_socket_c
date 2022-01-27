#include <string.h>
#include "handleDatabase.h"
#include "handleList.h"

FILE *openFile(const char *fileName, const char *mode) {
    FILE *file = fopen(fileName, mode);
    if (file == NULL) {
        printf("Can't open file %s\n", fileName);
        return NULL;
    }
    return file;
}

void readFileHistory() {
    FILE *file = openFile(FILE_HISTORY, "r");
    if (file == NULL) {
        printf("Can't open file %s for read\n", FILE_HISTORY);
        return;
    }

    char buff[MAX_LEN_BUFF + 1];
    while (!feof(file)) {
        fgets(buff, MAX_LEN_BUFF, file);
        if (!feof(file))
            buff[strlen(buff) - 1] = 0;
        addList(createDataHistory(buff), TAG_HISTORY);
    }
    fclose(file);
}


void readFileAccount() {
    FILE *file = openFile(FILE_ACCOUNT, "r");
    if (file == NULL) {
        printf("Can't open file %s for read\n", FILE_ACCOUNT);
        return;
    }
    char buff[MAX_LEN_BUFF + 1];
    while (!feof(file)) {
        fgets(buff, MAX_LEN_BUFF, file);
        if (!feof(file))
            buff[strlen(buff) - 1] = 0;
        addList(createDataAccount(buff), TAG_ACCOUNT);
    }
    fclose(file);
}

void readAllFileDataBase() {
    readFileAccount();
    readFileHistory();
}

void writeFileHistory(char *data) {
    FILE *file = openFile(FILE_HISTORY, "ab");
    fprintf(file, "\n%s", data);
    fclose(file);
}



void writeFileAccount(char *data) {
    FILE *file = openFile(FILE_ACCOUNT, "ab");
    fprintf(file, "\n%s", data);
    fclose(file);
}

