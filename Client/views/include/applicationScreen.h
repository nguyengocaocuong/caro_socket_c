#ifndef NETWORKPROGRAM_APPLICATIONSCREEN_H
#define NETWORKPROGRAM_APPLICATIONSCREEN_H

#include <gtk/gtk.h>
#include <netinet/in.h>

typedef struct {
    GtkWidget *window_home;
    GtkWidget *btn_login;
    GtkWidget *btn_register;
} HomeContainer;

typedef struct {
    GtkWidget *window_login;
    GtkWidget *btn_sign_in;
    GtkWidget *lbl_error;
    GtkWidget *btn_back;
    GtkWidget *entry_account;
    GtkWidget *entry_pass;
    GtkWidget *btn_reset_pass;
} LoginContainer;

typedef struct {
    GtkWidget *window_register;
    GtkWidget *btn_back;
    GtkWidget *lbl_error;
    GtkWidget *btn_register;
    GtkWidget *entry_account;
    GtkWidget *entry_pass;
    GtkWidget *entry_confirm_pass;

} RegisterContainer;

typedef struct {
    GtkWidget *window_game;
    GtkWidget *grid_caro;
    GtkWidget *btn_send;
    GtkWidget *btn_redo;
    GtkWidget *btn_undo;
    GtkWidget *btn_home;
    GtkWidget *box_message;
    GtkWidget *entry_message;
    GtkWidget *lbl_win_total;
    GtkWidget *lbl_lost_total;
    GtkWidget *lbl_status_game;
    GtkWidget *lbl_next_person;
    GtkWidget *fixed_main;
    GtkWidget *fixed_caro;
    GtkWidget *box_notify;
    GtkWidget *scroll;
} GameContainer;

typedef struct {
    GtkWidget *window_main;
    GtkWidget *image_main;
    GtkWidget *btn_history;
    GtkWidget *btn_online_account;
    GtkWidget *btn_new_game;
    GtkWidget *btn_home;
    GtkWidget *stack_main;
    GtkWidget *fixed_main;
    GtkWidget *fixed_history;
    GtkWidget *fixed_new_game;
    GtkWidget *fixed_online_person;
    GtkWidget *box_history;
    GtkWidget *box_online;
    GtkWidget *scroll;
    GtkWidget *scroll_online;
    GtkWidget *start;
    GtkWidget *btn_request;
    GtkWidget *entry_account;
    GtkWidget *scroll_notify;
    GtkWidget *box_notify;
    GtkWidget *btn_notify;
    GtkWidget *fixed_notify;
    GtkWidget *radio_play_with_machine;
    GtkWidget *radio_play_with_person;
} MainContainer;

typedef struct {
    HomeContainer homeContainer;
    LoginContainer loginContainer;
    RegisterContainer registerContainer;
    GameContainer gameContainer;
    MainContainer mainContainer;
} GameApplication;

typedef struct {
    GameApplication *gameApplication;
    struct sockaddr_in serverAddr;
    pthread_t childThreadId;
    GtkCssProvider *provider;
    GtkCssProvider *provider_main;
    int sockFd;
    int icon;
    int isNext;
    char person[30];
} UserData;

//Cấu trúc lưu trữ thông tin của một client, xuyên suốt toàn project
UserData userData;
#endif
