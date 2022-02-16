#include <styleScreen.h>
#include <gtk/gtk.h>
#include "constant.h"
#include "handleLogicMainScreen.h"
#include "handleClient.h"

void on_switch_stack_pain(GtkWidget *child) {
    gtk_stack_set_visible_child(GTK_STACK(userData.gameApplication->mainContainer.stack_main), child);
}

void on_show_history(PersonHistory *personHistory, int size) {
    GtkBox *boxHistory = GTK_BOX(userData.gameApplication->mainContainer.box_history);
    GtkCssProvider *provider_game = userData.provider_main;
    char tmp[5];
    gtk_container_foreach (GTK_CONTAINER (userData.gameApplication->mainContainer.box_history), (void*) gtk_widget_destroy, NULL);
    for (int i = 0; i < size; ++i) {
        GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
        gtk_widget_set_visible(GTK_WIDGET(box), TRUE);
        css_set(provider_game, box);
        add_class(box, "history");

        snprintf(tmp, 10, "%d", i + 1);
        GtkWidget *stt = gtk_label_new(tmp);
        gtk_widget_set_size_request(GTK_WIDGET(stt), 30, 40);
        gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(stt), FALSE, FALSE, 0);
        gtk_widget_set_visible(stt, TRUE);
        gtk_label_set_xalign(GTK_LABEL(stt), 0.3);


        GtkWidget *name = gtk_label_new(personHistory[i].name);
        gtk_widget_set_size_request(GTK_WIDGET(name), 190, 40);
        gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(name), FALSE, FALSE, 0);
        gtk_widget_set_visible(name, TRUE);
        gtk_label_set_xalign(GTK_LABEL(name), 0);


        GtkWidget *result = gtk_label_new(personHistory[i].result);
        gtk_widget_set_size_request(GTK_WIDGET(result), 45, 40);
        gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(result), FALSE, FALSE, 0);
        gtk_widget_set_visible(result, TRUE);
        gtk_label_set_xalign(GTK_LABEL(result), 0);

        GtkWidget *date = gtk_label_new(personHistory[i].date);
        gtk_widget_set_size_request(GTK_WIDGET(date), 90, 40);
        gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(date), FALSE, FALSE, 0);
        gtk_widget_set_visible(date, TRUE);
        gtk_label_set_xalign(GTK_LABEL(date), 0);


        gtk_box_pack_start(boxHistory, GTK_WIDGET(box), FALSE, FALSE, 0);
    }

    if(personHistory != NULL)free(personHistory);
}


void on_show_online(PersonHistory *personHistory, int size) {
    GtkBox *boxOnline = GTK_BOX(userData.gameApplication->mainContainer.box_online);
    GtkCssProvider *provider_game = userData.provider_main;
    char tmp[10];
    gtk_container_foreach (GTK_CONTAINER (userData.gameApplication->mainContainer.box_online), (void*) gtk_widget_destroy, NULL);

    for (int i = 0; i < size; ++i) {
        GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
        gtk_widget_set_visible(GTK_WIDGET(box), TRUE);
        css_set(provider_game, box);
        add_class(box, "history");
        snprintf(tmp, 10, "%d", i + 1);
        GtkWidget *stt = gtk_label_new(tmp);
        gtk_widget_set_size_request(GTK_WIDGET(stt), 30, 40);
        gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(stt), FALSE, FALSE, 0);
        gtk_widget_set_visible(stt, TRUE);
        gtk_label_set_xalign(GTK_LABEL(stt), 0.3);

        GtkWidget *name = gtk_label_new(personHistory[i].name);
        gtk_widget_set_size_request(GTK_WIDGET(name), 240, 40);
        gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(name), FALSE, FALSE, 0);
        gtk_widget_set_visible(name, TRUE);
        gtk_label_set_xalign(GTK_LABEL(name), 0);

        gtk_box_pack_start(boxOnline, GTK_WIDGET(box), FALSE, FALSE, 0);
    }

    if(personHistory != NULL) free(personHistory);
}

void on_history_clicked(GtkButton *button) {
    remove_class(userData.gameApplication->mainContainer.btn_home, "active1");
    remove_class(userData.gameApplication->mainContainer.btn_history, "active");
    remove_class(userData.gameApplication->mainContainer.btn_new_game, "active");
    remove_class(userData.gameApplication->mainContainer.btn_online_account, "active");
    remove_class(userData.gameApplication->mainContainer.btn_notify, "active");

    on_switch_stack_pain(userData.gameApplication->mainContainer.fixed_history);
    add_class(userData.gameApplication->mainContainer.btn_history, "active");
    viewHistory(userData.sockFd);
}

void on_request_clicked(GtkButton *button) {
    const gchar *account = gtk_entry_get_text(GTK_ENTRY(userData.gameApplication->mainContainer.entry_account));
    printf("%s\n",account);
    sendRequestNewGame((char *) account,
                       userData.sockFd);
}

void on_start_clicked(GtkButton *button) {
    gtk_label_set_text(GTK_LABEL(userData.gameApplication->gameContainer.lbl_next_person),userData.person);
    gtk_widget_show(userData.gameApplication->gameContainer.window_game);
    gtk_widget_hide(userData.gameApplication->mainContainer.window_main);
}

void on_new_game_clicked(GtkButton *button) {
    remove_class(userData.gameApplication->mainContainer.btn_home, "active1");
    remove_class(userData.gameApplication->mainContainer.btn_history, "active");
    remove_class(userData.gameApplication->mainContainer.btn_new_game, "active");
    remove_class(userData.gameApplication->mainContainer.btn_online_account, "active");
    remove_class(userData.gameApplication->mainContainer.btn_notify, "active");

    on_switch_stack_pain(userData.gameApplication->mainContainer.fixed_new_game);
    add_class(userData.gameApplication->mainContainer.btn_new_game, "active");
}

void on_online_account_clicked(GtkButton *button) {
    remove_class(userData.gameApplication->mainContainer.btn_history, "active");
    remove_class(userData.gameApplication->mainContainer.btn_new_game, "active");
    remove_class(userData.gameApplication->mainContainer.btn_online_account, "active");
    remove_class(userData.gameApplication->mainContainer.btn_home, "active1");
    remove_class(userData.gameApplication->mainContainer.btn_notify, "active");

    on_switch_stack_pain(userData.gameApplication->mainContainer.fixed_online_person);
    add_class(userData.gameApplication->mainContainer.btn_online_account, "active");
    viewListOnlineAccount(userData.sockFd);
}

void on_notify_clicked(GtkButton *button) {
    remove_class(userData.gameApplication->mainContainer.btn_history, "active");
    remove_class(userData.gameApplication->mainContainer.btn_new_game, "active");
    remove_class(userData.gameApplication->mainContainer.btn_online_account, "active");
    remove_class(userData.gameApplication->mainContainer.btn_notify, "active");
    remove_class(userData.gameApplication->mainContainer.btn_home, "active1");

    on_switch_stack_pain(userData.gameApplication->mainContainer.fixed_notify);
    add_class(userData.gameApplication->mainContainer.btn_notify, "active");
}

void on_home_clicked(GtkButton *button) {
    remove_class(userData.gameApplication->mainContainer.btn_history, "active");
    remove_class(userData.gameApplication->mainContainer.btn_new_game, "active");
    remove_class(userData.gameApplication->mainContainer.fixed_main, "active");
    remove_class(userData.gameApplication->mainContainer.btn_notify, "active");

    on_switch_stack_pain(userData.gameApplication->mainContainer.fixed_main);
    add_class(userData.gameApplication->mainContainer.btn_home, "active1");
}


void gtk_main_quit_main(GtkWindow *window) {
    send(userData.sockFd, PREFIX_CLOSE, MAX_LEN_BUFF, 0);
    close(userData.sockFd);
    gtk_main_quit();
}


void on_add_notify(GtkWidget *notify) {
    gtk_box_pack_start(GTK_BOX(userData.gameApplication->mainContainer.box_notify), notify, FALSE, FALSE, 0);
}

void on_click_new_game_no(GtkButton *button) {
    printf("Khong dong y choi!\n");
}

void on_click_new_game_ok(GtkButton *button) {
    sendMessageAcceptPlay();
}