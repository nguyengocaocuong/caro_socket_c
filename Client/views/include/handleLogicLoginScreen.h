#ifndef NETWORKPROGRAM_HANDLELOGICLOGINSCREEN_H
#define NETWORKPROGRAM_HANDLELOGICLOGINSCREEN_H

#include "applicationScreen.h"
#include "handleClient.h"
/**
 *
 * @param window
 */
void gtk_main_quit_login(GtkWindow *window);
/**
 *
 * @param button
 */
void on_back_clicked(GtkButton *button);
/**
 *
 * @param button
 */
void on_sign_in_clicked(GtkButton *button);

#endif
