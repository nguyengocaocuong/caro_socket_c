#ifndef NETWORKPROGRAM_HANDLELOGICLOGINSCREEN_H
#define NETWORKPROGRAM_HANDLELOGICLOGINSCREEN_H

#include "applicationScreen.h"
#include "handleClient.h"
void gtk_main_quit_login(GtkWindow *window, UserData *userData);

void on_back_clicked(GtkButton *button, UserData *userData);

void on_sign_in_clicked(GtkButton *button, UserData *userData);

#endif
