#ifndef NETWORKPROGRAM_HANDLELOGICSGAMECREEN_H
#define NETWORKPROGRAM_HANDLELOGICGAMESCREEN_H

#include "applicationScreen.h"

void gtk_main_quit_game(GtkWindow *window, UserData *userData);

void on_clicked_game_undo(GtkButton *button, UserData *userData);

void on_clicked_game_send(GtkButton *button, UserData *userData);

void on_clicked_game_home(GtkButton *button, UserData *userData);

void on_clicked_game_redo(GtkButton *button, UserData *userData);

void on_clicked_cell(GtkButton *button, UserData *userData);

void on_clicked_set_cell(int row, int cow, UserData *userData);

void set_win_cell(int row, int col, UserData *userData,int tag);

void add_message(GtkWidget *message, UserData *userData);

void on_add_message_recv(char *message, UserData *userData);

void clear_entry_message(UserData *userData);

void change_label_next_person(UserData *userData);

void show_dialog_time_out(UserData *userData);

void set_label_status_game(UserData *userData, char *status);

#endif
