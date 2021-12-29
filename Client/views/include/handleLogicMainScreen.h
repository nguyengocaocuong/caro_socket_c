#ifndef NETWORKPROGRAM_HANDLELOGICSCREEN_H
#define NETWORKPROGRAM_HANDLELOGICSCREEN_H

#include "structData.h"
#include "applicationScreen.h"

void on_show_history(PersonHistory *personHistory, int size, UserData *userData);

void on_show_online(PersonHistory *personHistory, int size, UserData *userData);

void on_history_clicked(GtkButton *button, UserData *userData);

void on_new_game_clicked(GtkButton *button, UserData *userData);

void on_online_account_clicked(GtkButton *button, UserData *userData);

void gtk_main_quit_main(GtkWindow *window, UserData *userData);

void on_switch_stack_pain(GtkWidget *child, UserData *userData);

void on_home_clicked(GtkButton *button, UserData *userData);

void on_start_clicked(GtkButton *button, UserData *userData);

void on_request_clicked(GtkButton *button, UserData *userData);

void on_notify_clicked(GtkButton *button, UserData *userData);

void on_add_notify(GtkWidget *notify, UserData *userData);

void on_click_add_friend_no(GtkButton *button, UserData *userData);

void on_click_add_friend_ok(GtkButton *button, UserData *userData);

void on_click_new_game_ok(GtkButton *button, UserData *userData);

void on_click_new_game_no(GtkButton *button, UserData *userData);

#endif
