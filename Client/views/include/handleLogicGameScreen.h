#ifndef NETWORKPROGRAM_HANDLELOGICSGAMECREEN_H
#define NETWORKPROGRAM_HANDLELOGICGAMESCREEN_H

#include "applicationScreen.h"
/**
 * Hàm này xử lý close cửa sổ window hame
 * @param window
 */
void gtk_main_quit_game(GtkWindow *window);
/**
 *
 * @param button
 */
void on_clicked_game_undo(GtkButton *button);
/**
 *
 * @param button
 */
void on_clicked_game_send(GtkButton *button);
/**
 *
 * @param button
 */
void on_clicked_game_home(GtkButton *button);
/**
 *
 * @param button
 */
void on_clicked_game_redo(GtkButton *button);
/**
 *
 * @param button
 */
void on_clicked_cell(GtkButton *button);
/**
 *
 * @param row
 * @param cow
 */
void on_clicked_set_cell(int row, int cow);
/**
 *
 * @param row
 * @param col
 * @param tag
 */
void set_win_cell(int row, int col,int tag);
/**
 *
 * @param message
 */
void add_message(GtkWidget *message);
/**
 *
 * @param message
 */
void on_add_message_recv(char *message);
/**
 *
 */
void clear_entry_message();
/**
 *
 */
void change_label_next_person();
/**
 *
 * @param status
 */
void set_label_status_game(char *status);


#endif
