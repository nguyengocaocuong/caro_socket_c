#include <stdio.h>
#include <serverHeper.h>
#include "initServer.h"
#include "handleServer.h"


int main(int argc, char *argv[]) {
    if (argc > 0 && initServer(argv[1])) {
        printf("Can't create socket!\n");
        return -1;
    }

    struct timeval timeval;
    while (1) {
        timeval.tv_sec = 2;
        timeval.tv_usec = 0;
        //sau 2s cập nhật lại danh sách lắng nghe một lần, bởi vì sẽ có nhưng client thoát khỏi ván game, và trở lại luồng chính
        updateNewReadFds();
        int selectStatus = select(serverData.maxFd, &(serverData.readFds), NULL, NULL, &timeval);
        if (selectStatus == -1) {
            printf("Close server :\n");
            break;
        } else if (selectStatus == 0) {
        } else {
            handleSelect(&serverData);
        }
    }
    freeServerData(&serverData);
    return 0;
}
