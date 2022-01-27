#ifndef NETWORKPROGRAM_HANDLELOGICSGAMECREEN_H
#define NETWORKPROGRAM_HANDLELOGICGAMESCREEN_H

#include "applicationScreen.h"

void gtk_main_quit_game(GtkWindow *window);

void on_clicked_game_undo(GtkButton *button);

void on_clicked_game_send(GtkButton *button);

void on_clicked_game_home(GtkButton *button);

void on_clicked_game_redo(GtkButton *button);

void on_clicked_cell(GtkButton *button);

void on_clicked_set_cell(int row, int cow);

void set_win_cell(int row, int col,int tag);

void add_message(GtkWidget *message);

void on_add_message_recv(char *message);

void clear_entry_message();

void change_label_next_person();

void show_dialog_time_out();

void set_label_status_game(char *status);


#endif
