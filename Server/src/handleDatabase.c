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

void readFileHistory(ServerData *serverData) {
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
        addList(serverData, createDataHistory(buff), TAG_HISTORY);
    }
    fclose(file);
}

void readFileFriend(ServerData *serverData) {
    FILE *file = openFile(FILE_FRIEND, "r");
    if (file == NULL) {
        printf("Can't open file %s for read\n", FILE_FRIEND);
        return;
    }

    char buff[MAX_LEN_BUFF + 1];
    while (!feof(file)) {
        fgets(buff, MAX_LEN_BUFF, file);
        if (!feof(file))
            buff[strlen(buff) - 1] = 0;
        addList(serverData, createDataFriend(buff), TAG_FRIEND);
    }
    fclose(file);
}

void readFileAccount(ServerData *serverData) {
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
        addList(serverData, createDataAccount(buff), TAG_ACCOUNT);
    }
    fclose(file);
}

void readAllFileDataBase(ServerData *serverData) {
    readFileAccount(serverData);
    readFileFriend(serverData);
    readFileHistory(serverData);
}

void writeFileHistory(ServerData *serverData,char *data){
    FILE *file = openFile(FILE_HISTORY, "ab");
    fprintf(file,"\n%s",data);
    fclose(file);
}


void writeFileFriend(ServerData *serverData) {

}

void writeFileAccount(ServerData *serverData,char *data) {
    FILE *file = openFile(FILE_ACCOUNT, "ab");
    fprintf(file,"\n%s",data);
    fclose(file);
}

