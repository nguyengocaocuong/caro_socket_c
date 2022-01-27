#include "handleLogicHomeScreen.h"
#include "constant.h"
void on_login_clicked(GtkButton *button){
    gtk_widget_hide(userData.gameApplication->homeContainer.window_home);
    gtk_widget_show(userData.gameApplication->loginContainer.window_login);
}
void on_register_clicked(GtkButton *button){
    gtk_widget_hide(userData.gameApplication->homeContainer.window_home);
    gtk_widget_show(userData.gameApplication->registerContainer.window_register);
}
void gtk_main_quit_home(GtkWindow *window){
    send(userData.sockFd, PREFIX_CLOSE, MAX_LEN_BUFF, 0);
    close(userData.sockFd);
    gtk_main_quit();
}
