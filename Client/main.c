#include "initScreen.h"
#include "initClient.h"
#include "clientError.h"
int main(int argc, char *argv[]) {

    if (argc < 3)
        return ERROR_INVALID_PARAMS;
    gtk_init(&argc, &argv);
    GameApplication gameApplication;

    if ((userData.sockFd = initSocket(argv[1], atoi(argv[2]))) < 0)
        return userData.sockFd;
    userData.gameApplication = &gameApplication;
    initApplication(&userData);
    gtk_widget_show(gameApplication.homeContainer.window_home);
    gtk_main();
    return 0;
}
