#include "handleLogicRegisterScreen.h"
#include "handleClient.h"

void gtk_main_quit_rs_login(GtkWindow *window) {
    send(userData.sockFd, PREFIX_CLOSE, MAX_LEN_BUFF, 0);
    close(userData.sockFd); 
    gtk_main_quit();
}

void on_back_rs_clicked(GtkButton *button) {
    gtk_widget_show(userData.gameApplication->homeContainer.window_home);
    gtk_widget_hide(userData.gameApplication->registerContainer.window_register);
}

void on_register_rs_clicked(GtkButton *button) {
    char *accountName = (char *) gtk_entry_get_text(
            GTK_ENTRY(userData.gameApplication->registerContainer.entry_account));
    char *pass = (char *) gtk_entry_get_text(GTK_ENTRY(userData.gameApplication->registerContainer.entry_pass));
    char *confirmPass = (char *) gtk_entry_get_text(
            GTK_ENTRY(userData.gameApplication->registerContainer.entry_confirm_pass));
    if (strcmp(confirmPass, pass) != 0) {
        gtk_label_set_text(GTK_LABEL(userData.gameApplication->registerContainer.lbl_error), "Mật khẩu không khớp!");
        gtk_widget_set_visible(userData.gameApplication->registerContainer.lbl_error, TRUE);
        return;
    }
    int status = registerAccount(accountName, pass, userData.sockFd);
    if (status)
        return;
    gtk_widget_show_all(userData.gameApplication->mainContainer.window_main);
    gtk_widget_hide(userData.gameApplication->registerContainer.window_register);
}