#ifndef NETWORKPROGRAM_HANDLELOGICSCREEN_H
#define NETWORKPROGRAM_HANDLELOGICSCREEN_H

#include "structData.h"
#include "applicationScreen.h"
/**
 *
 * @param personHistory
 * @param size
 */
void on_show_history(PersonHistory *personHistory, int size);
/**
 *
 * @param personHistory
 * @param size
 */
void on_show_online(PersonHistory *personHistory, int size);

void on_history_clicked(GtkButton *button);

void on_new_game_clicked(GtkButton *button);

void on_online_account_clicked(GtkButton *button);

void gtk_main_quit_main(GtkWindow *window);

void on_switch_stack_pain(GtkWidget *child);

void on_home_clicked(GtkButton *button);

void on_start_clicked(GtkButton *button);

void on_request_clicked(GtkButton *button);

void on_notify_clicked(GtkButton *button);

void on_add_notify(GtkWidget *notify);

void on_click_new_game_ok(GtkButton *button);

void on_click_new_game_no(GtkButton *button);

#endif
