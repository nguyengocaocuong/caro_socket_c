#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>

#include "clientHeper.h"
#include "constant.h"
#include "handleLogicGameScreen.h"
#include "handleLogicMainScreen.h"
#include "styleScreen.h"


int registerAccount(char *accountName, char *password, int sockFd) {
    char *sendData = makeSendDataRegister(accountName, password);
    char recvData[MAX_LEN_BUFF];
    int recvSize = 0;
    printf("%s\n", sendData);
    send(sockFd, sendData, MAX_LEN_BUFF, 0);
    if (sendData != NULL)
        free(sendData);

    recvSize = recv(sockFd, recvData, MAX_LEN_BUFF, 0);
    recvData[recvSize] = 0;
    printf("%s\n", recvData);
    if (strcmp(PREFIX_SUCCESS, recvData) == 0)
        return 0;
    return 1;
}

int loginAccount(char *accountName, char *password, int sockFd) {
    char recvData[MAX_LEN_BUFF];
    int recvSize = 0;
    char *sendData = makeSendDataLogin(accountName, password);

    send(sockFd, sendData, MAX_LEN_BUFF, 0);
    printf("%s\n", sendData);
    if (sendData != NULL)
        free(sendData);

    recvSize = recv(sockFd, recvData, MAX_LEN_BUFF, 0);
    recvData[recvSize] = 0;
    printf("%s\n", recvData);

    if (strcmp(PREFIX_SUCCESS, recvData) == 0)
        return 0;
    return 1;
}

void viewHistory(int sockFd) {
    send(sockFd, PREFIX_HISTORY, MAX_LEN_BUFF, 0);
    printf("%s\n", PREFIX_HISTORY);
}

void viewListOnlineAccount(int sockFd) {
    send(sockFd, PREFIX_ONLINE, MAX_LEN_BUFF, 0);
    printf("%s\n", PREFIX_ONLINE);
}

void sendMessage(char *message, int sockFd) {
    char *sendData = makeSendDataMessage(message);

    send(sockFd, sendData, MAX_LEN_BUFF, 0);
    printf("%s\n", sendData);
    if (sendData != NULL)
        free(sendData);
}

void sendRequestNewGame(char *account, int sockFd) {
    char *sendData = makeSendDataNewGame(account);
    send(sockFd, sendData, MAX_LEN_BUFF, 0);
    printf("%s\n", sendData);
    if (sendData != NULL)
        free(sendData);
}

void sendNextGameStatus(int row, int col, int sockFd) {
    char *sendData = makeSendDataNextGameStatus(row, col);
    send(sockFd, sendData, MAX_LEN_BUFF, 0);
    printf("%s\n", sendData);
    if (sendData != NULL)
        free(sendData);
}

void addFriend(char *account, int sockFd) {
    char *sendData = makeSendDataRAddFriend(account);
    send(sockFd, sendData, MAX_LEN_BUFF, 0);
    printf("%s\n", sendData);
    if (sendData != NULL)
        free(sendData);
}

void handleRecvData(char *dataRecv, UserData *userData) {
    printf("%s\n", dataRecv);
    char *tmp = (char *) calloc(1, MAX_LEN_BUFF);
    strcpy(tmp, dataRecv);
    char *token = strtok(tmp, SEPARATOR);
    if (strcmp(token, PREFIX_SUCCESS) == 0) {
        gtk_widget_show(userData->gameApplication->mainContainer.window_main);
        gtk_widget_hide(userData->gameApplication->homeContainer.window_home);
        if (tmp != NULL)
            free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_CELL) == 0) {
        int row, col;
        separationDataCell(dataRecv, &row, &col);
        on_clicked_set_cell(row, col, userData);
        if (tmp != NULL)
            free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_MESSAGE) == 0) {
        char *message = separationDataMessage(dataRecv);
//        printf("Nhan : %s\n",message);
        on_add_message_recv(message, userData);
        if (message != NULL)
            free(message);
        if (tmp != NULL)
            free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_HISTORY) == 0) {
        int size;
        PersonHistory *personHistories = separationDataHistory(dataRecv, &size);
        on_show_history(personHistories, size, userData);
        if (tmp != NULL)
            free(tmp);
        return;
    }

    if (strcmp(token, PREFIX_ONLINE) == 0) {
        int size;
        PersonHistory *personOnline = separationDataOnline(dataRecv, &size);
        on_show_online(personOnline, size, userData);
        if (tmp != NULL)
            free(tmp);
        return;
    }

    if (strcmp(token, PREFIX_ADD_FRIEND_OK) == 0) {
        char *account = separationDataAddFriend(dataRecv);

        GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
        gtk_widget_set_visible(GTK_WIDGET(box), TRUE);

        css_set(userData->provider_main, box);
        add_class(box, "history");

        GtkWidget *name = gtk_label_new(account);
        gtk_widget_set_size_request(GTK_WIDGET(name), 200, 40);
        gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(name), FALSE, FALSE, 0);
        gtk_widget_set_visible(name, TRUE);
        gtk_label_set_xalign(GTK_LABEL(name), 0.3);
        gtk_label_set_xalign(GTK_LABEL(name), 0);

        GtkWidget *btnOk = gtk_button_new_with_label("Kết bạn");
        gtk_widget_set_size_request(GTK_WIDGET(btnOk), 60, 36);
        gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(btnOk), FALSE, FALSE, 0);
        gtk_widget_set_name(btnOk, account);
        g_signal_connect(GTK_WIDGET(btnOk), "clicked", on_click_add_friend_ok, userData->sockFd);
        css_set(userData->provider_main, btnOk);
        add_class(btnOk, "btn-add");
        gtk_widget_set_visible(btnOk, TRUE);

        GtkWidget *btnNo = gtk_button_new_with_label("Từ chối");
        gtk_widget_set_size_request(GTK_WIDGET(btnNo), 60, 36);
        gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(btnNo), FALSE, FALSE, 0);
        gtk_widget_set_name(btnNo, account);
        g_signal_connect(GTK_WIDGET(btnNo), "clicked", on_click_add_friend_no, userData->sockFd);
        css_set(userData->provider_main, btnNo);
        add_class(btnNo, "btn-add");
        gtk_widget_set_visible(btnNo, TRUE);
        on_add_notify(box, userData);
        if (tmp != NULL)
            free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_NEW_GAME) == 0) {
        char *account = separationDataAddFriend(dataRecv);

        GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
        gtk_widget_set_visible(GTK_WIDGET(box), TRUE);

        css_set(userData->provider_main, box);
        add_class(box, "history");

        strcpy(userData->person, account);

        GtkWidget *name = gtk_label_new(account);
        gtk_widget_set_size_request(GTK_WIDGET(name), 200, 40);
        gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(name), FALSE, FALSE, 0);
        gtk_widget_set_visible(name, TRUE);
        gtk_label_set_xalign(GTK_LABEL(name), 0);
        gtk_label_set_xalign(GTK_LABEL(name), 0.3);

        GtkWidget *btnOk = gtk_button_new_with_label("Chơi");
        gtk_widget_set_size_request(GTK_WIDGET(btnOk), 60, 36);
        gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(btnOk), FALSE, FALSE, 0);
        gtk_widget_set_name(btnOk, account);
        g_signal_connect(GTK_WIDGET(btnOk), "clicked", on_click_new_game_ok, userData);
        css_set(userData->provider_main, btnOk);
        add_class(btnOk, "btn-add");
        gtk_widget_set_visible(btnOk, TRUE);

        GtkWidget *btnNo = gtk_button_new_with_label("Từ chối");
        gtk_widget_set_size_request(GTK_WIDGET(btnNo), 60, 36);
        gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(btnNo), FALSE, FALSE, 0);
        gtk_widget_set_name(btnNo, account);
        g_signal_connect(GTK_WIDGET(btnNo), "clicked", on_click_new_game_no, userData->sockFd);
        css_set(userData->provider_main, btnNo);
        add_class(btnNo, "btn-add");
        gtk_widget_set_visible(btnNo, TRUE);
        on_add_notify(box, userData);
        free(account);
        if (tmp != NULL)
            free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_ACCEPT_PLAY) == 0) {
        userData->icon = O_ICON;
        userData->isNext = NEXT_NOT_YOU;
        char *account = separationDataAcceptPlay(dataRecv);
        strcpy(userData->person, account);
        gtk_widget_set_visible(userData->gameApplication->mainContainer.start, TRUE);
        on_new_game_clicked(NULL, userData);
        if (tmp != NULL)
            free(tmp);
        if (account != NULL)
            free(account);
        return;
    }
    if (strcmp(token, PREFIX_PLAY) == 0) {
        userData->icon = X_ICON;
        userData->isNext = NEXT_YOU;
        gtk_widget_set_visible(userData->gameApplication->mainContainer.start, TRUE);
        on_new_game_clicked(NULL, userData);
        if (tmp != NULL)
            free(tmp);
        return;
    }
}


void sendMessageAcceptPlay(UserData *userData) {
    char *sendData = makeSendDataAcceptPlay(userData->person);
    printf("%s\n", sendData);
    send(userData->sockFd, sendData, MAX_LEN_BUFF, 0);
    if (sendData != NULL)
        free(sendData);
}