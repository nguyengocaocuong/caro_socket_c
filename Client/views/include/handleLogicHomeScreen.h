#ifndef NETWORKPROGRAM_HANDLELOGICSHOMECREEN_H
#define NETWORKPROGRAM_HANDLELOGICHOMESCREEN_H

#include "applicationScreen.h"

void on_login_clicked(GtkButton *button, UserData *userData);

void on_register_clicked(GtkButton *button, UserData *userData);

void gtk_main_quit_home(GtkWindow *window, UserData *userData);

#endif
