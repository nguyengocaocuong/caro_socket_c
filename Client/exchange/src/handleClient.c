#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <initScreen.h>

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
    int recvSize;
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
    if (account == NULL || strlen(account) < 1) {
        send(sockFd, "$NEW_GAME#", MAX_LEN_BUFF, 0);
        strcpy(userData.person, "Máy");
        return;
    }
    char *sendData = makeSendDataNewGame(account);
    printf("%s\n", sendData);
    send(sockFd, sendData, MAX_LEN_BUFF, 0);
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


void handleRecvData(char *dataRecv) {
    printf("%s\n", dataRecv);
    char *tmp = (char *) calloc(1, MAX_LEN_BUFF);
    strcpy(tmp, dataRecv);
    char *token = strtok(tmp, SEPARATOR);
    if (strcmp(token, PREFIX_SUCCESS) == 0) {
        gtk_widget_show(userData.gameApplication->mainContainer.window_main);
        gtk_widget_hide(userData.gameApplication->homeContainer.window_home);
        if (tmp != NULL)
            free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_CELL) == 0) {
        int row, col;
        separationDataCell(dataRecv, &row, &col);
        printf("%d-%d\n", row, col);
        on_clicked_set_cell(row, col);
        if (tmp != NULL)
            free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_MESSAGE) == 0) {
        char *message = separationDataMessage(dataRecv);
        on_add_message_recv(message);
        if (message != NULL)
            free(message);
        if (tmp != NULL)
            free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_HISTORY) == 0) {
        int size;
        PersonHistory *personHistories = separationDataHistory(dataRecv, &size);
        on_show_history(personHistories, size);
        if (tmp != NULL)
            free(tmp);
        return;
    }

    if (strcmp(token, PREFIX_ONLINE) == 0) {
        int size;
        PersonHistory *personOnline = separationDataOnline(dataRecv, &size);
        on_show_online(personOnline, size);
        if (tmp != NULL)
            free(tmp);
        return;
    }

    if (strcmp(token, PREFIX_NEW_GAME) == 0) {
        strtok(dataRecv, SEPARATOR);
        char *account = strtok(NULL, SEPARATOR);

        GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
        gtk_widget_set_visible(GTK_WIDGET(box), TRUE);

        css_set(userData.provider_main, box);
        add_class(box, "history");

        strcpy(userData.person, account);

        GtkWidget *name = gtk_label_new(account);
        gtk_widget_set_size_request(GTK_WIDGET(name), 200, 40);
        gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(name), FALSE, FALSE, 0);
        gtk_widget_set_visible(name, TRUE);
        gtk_label_set_xalign(GTK_LABEL(name), 0);
        gtk_label_set_xalign(GTK_LABEL(name), 0.3);

        GtkWidget *btnOk = gtk_button_new_with_label("Ok");
        gtk_widget_set_size_request(GTK_WIDGET(btnOk), 60, 36);
        gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(btnOk), FALSE, FALSE, 0);
        gtk_widget_set_name(btnOk, account);
        g_signal_connect(GTK_WIDGET(btnOk), "clicked", G_CALLBACK(on_click_new_game_ok), NULL);
        css_set(userData.provider_main, btnOk);
        add_class(btnOk, "btn-add");
        gtk_widget_set_visible(btnOk, TRUE);

        GtkWidget *btnNo = gtk_button_new_with_label("Từ chối");
        gtk_widget_set_size_request(GTK_WIDGET(btnNo), 60, 36);
        gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(btnNo), FALSE, FALSE, 0);
        gtk_widget_set_name(btnNo, account);
        g_signal_connect(GTK_WIDGET(btnNo), "clicked", G_CALLBACK(on_click_new_game_no), NULL);
        css_set(userData.provider_main, btnNo);
        add_class(btnNo, "btn-add");
        gtk_widget_set_visible(btnNo, TRUE);
        on_add_notify(box);
//        free(account);
        if (tmp != NULL)
            free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_ACCEPT_PLAY) == 0) {
        userData.icon = O_ICON;
        userData.isNext = NEXT_NOT_YOU;
        char *account = separationDataAcceptPlay(dataRecv);
        strcpy(userData.person, account);
        pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;
        pthread_mutex_lock(&counter_mutex);
        gtk_widget_set_opacity(userData.gameApplication->mainContainer.start, 1);
        on_new_game_clicked(NULL);
        pthread_mutex_unlock(&counter_mutex);
        if (tmp != NULL)
            free(tmp);
        if (account != NULL)
            free(account);
        return;
    }
    if (strcmp(token, PREFIX_PLAY) == 0) {
//        printf("You play first\n");
        userData.icon = X_ICON;
        userData.isNext = NEXT_YOU;
        gtk_label_set_text(GTK_LABEL(userData.gameApplication->gameContainer.lbl_next_person), "bạn");
        pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;
        pthread_mutex_lock(&counter_mutex);
        gtk_widget_set_opacity(userData.gameApplication->mainContainer.start, 1);
        pthread_mutex_unlock(&counter_mutex);
        on_new_game_clicked(NULL);
        if (tmp != NULL)
            free(tmp);
        return;
    }

    if (strcmp(token, PREFIX_WIN) == 0) {
        userData.isNext = END_GAME;
        set_label_status_game("Bạn thắng");
        set_win_cell(dataRecv[7] - '0', dataRecv[5] - '0', 2);
        set_win_cell(dataRecv[11] - '0', dataRecv[9] - '0', 2);
        set_win_cell(dataRecv[15] - '0', dataRecv[13] - '0', 2);
        set_win_cell(dataRecv[19] - '0', dataRecv[17] - '0', 2);
        set_win_cell(dataRecv[23] - '0', dataRecv[21] - '0', 2);
        if (tmp != NULL)
            free(tmp);
        return;
    }

    if (strcmp(token, PREFIX_LOST) == 0) {
        userData.isNext = END_GAME;
        set_label_status_game("Bạn thua");
        set_win_cell(dataRecv[8] - '0', dataRecv[6] - '0', 1);
        set_win_cell(dataRecv[12] - '0', dataRecv[10] - '0', 1);
        set_win_cell(dataRecv[16] - '0', dataRecv[14] - '0', 1);
        set_win_cell(dataRecv[20] - '0', dataRecv[18] - '0', 1);
        set_win_cell(dataRecv[24] - '0', dataRecv[22] - '0', 1);
        userData.isNext = END_GAME;
        if (tmp != NULL)
            free(tmp);
        return;
    }
    if (strcmp(token, PREFIX_END_GAME) == 0) {
        userData.isNext = END_GAME;
        gtk_widget_set_opacity(userData.gameApplication->gameContainer.box_notify, 1);
        initGameScreen();
        gtk_widget_set_opacity(userData.gameApplication->mainContainer.start, 0);
        gtk_entry_set_text(GTK_ENTRY(userData.gameApplication->mainContainer.entry_account), "");
    }
}


void sendMessageAcceptPlay() {
    char *sendData = makeSendDataAcceptPlay(userData.person);
    printf("%s\n", sendData);
    send(userData.sockFd, sendData, MAX_LEN_BUFF, 0);
    if (sendData != NULL)
        free(sendData);
}