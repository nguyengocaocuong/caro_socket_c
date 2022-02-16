#include <sys/socket.h>
#include <stdlib.h>
#include <netdb.h>

#include "initServer.h"
#include "constant.h"
#include "handleDatabase.h"
int initServer(char *port) {
    int opt = 1;
    serverData.listenFD = socket(AF_INET, SOCK_STREAM, 0);
    if(setsockopt(serverData.listenFD, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    serverData.client = NULL;
    serverData.account = NULL;
    serverData.friend = NULL;
    serverData.history = NULL;
    serverData.serverAddr.sin_family = AF_INET;
    serverData.serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverData.serverAddr.sin_port = htons(atoi(port));

//run bug
//    serverData.serverAddr.sin_port = htons(5501);
    bind(serverData.listenFD, (struct sockaddr *) &(serverData.serverAddr), sizeof(serverData.serverAddr));
    listen(serverData.listenFD, MAX_ACCEPT_CLIENT);
    serverData.maxFd = serverData.listenFD + 1;

    readAllFileDataBase();
    return 0;
}


