#include <stdio.h>
#include <serverHeper.h>
#include "initServer.h"
#include "handleServer.h"


int main(int argc, char *argv[]) {
//    if (argc > 0 && initServer(&serverData, argv[1])) {
//        printf("Can't create socket!\n");
//        return -1;
//    }
    initServer(argv[1]);
    while (1) {
        updateNewReadFds(&serverData);
        int selectStatus = select(serverData.maxFd, &(serverData.readFds), NULL, NULL, NULL);
        if (selectStatus == -1) {
            printf("Close server :\n");
            break;
        } else if (selectStatus == 0) {
            printf("Het thoi gian cho!\n");
            printf("Close server :\n");
            break;
        } else {
            handleSelect(&serverData);
        }
    }

    freeServerData(&serverData);
    return 0;
}
