#include "handleLogicLoginScreen.h"
#include "handleThread.h"

void gtk_main_quit_login(GtkWindow *window, UserData *userData) {

}

void on_back_clicked(GtkButton *button, UserData *userData) {
    gtk_widget_show(userData->gameApplication->homeContainer.window_home);
    gtk_widget_hide(userData->gameApplication->loginContainer.window_login);
}

void on_sign_in_clicked(GtkButton *button, UserData *userData) {
    int status = loginAccount(
            (char *) gtk_entry_get_text(GTK_ENTRY(userData->gameApplication->loginContainer.entry_account)),
            (char *) gtk_entry_get_text(GTK_ENTRY(userData->gameApplication->loginContainer.entry_pass)),
            userData->sockFd);
    if (status) {
        gtk_widget_set_visible(userData->gameApplication->loginContainer.lbl_error, TRUE);
        return;
    }
    gtk_widget_set_visible(userData->gameApplication->loginContainer.lbl_error, FALSE);
    gtk_widget_show(userData->gameApplication->mainContainer.window_main);
    gtk_widget_hide(userData->gameApplication->loginContainer.window_login);

    int ret;

//    Set priority
    struct sched_param schedParam;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_getschedparam(&attr, &schedParam);
    schedParam.sched_priority = 50;

    pthread_attr_setschedpolicy(&attr, SCHED_RR);
    pthread_attr_setschedparam(&attr, &schedParam);
    ret = pthread_create(&(userData->childThreadId), NULL, multiModeHandle, userData);
    if (ret) {
        printf("pthread_create() error number=%d\n", ret);
        return;
    }
}