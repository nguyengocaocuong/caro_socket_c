#include <initScreen.h>
#include "handleClient.h"


void change_label_next_person() {
    gtk_label_set_text(GTK_LABEL(userData.gameApplication->gameContainer.lbl_next_person),
                       userData.isNext == NEXT_YOU ? "bạn" :
                       userData.person);
}

void gtk_main_quit_game(GtkWindow *window) {
    send(userData.sockFd, PREFIX_END_GAME, MAX_LEN_BUFF, 0);
    gtk_widget_set_opacity(userData.gameApplication->mainContainer.start,0);
    gtk_entry_set_text(GTK_ENTRY(userData.gameApplication->mainContainer.entry_account),"");
    initGameScreen();
    gtk_widget_hide(userData.gameApplication->gameContainer.window_game);
    gtk_widget_show(userData.gameApplication->mainContainer.window_main);
}

void on_clicked_game_undo(GtkButton *button) {
    printf("%s\n", "HandleClickUndoGame");
}

void add_message(GtkWidget *message) {
    pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&counter_mutex);
    GtkWidget *box = userData.gameApplication->gameContainer.box_message;
    gtk_box_pack_start(GTK_BOX(box), message, FALSE, FALSE, 0);
    pthread_mutex_unlock(&counter_mutex);
}

void clear_entry_message() {
    gtk_entry_set_text(GTK_ENTRY(userData.gameApplication->gameContainer.entry_message), "");
}

void on_clicked_game_send(GtkButton *button) {
    if(userData.isNext == END_GAME) return;
    const gchar *message = gtk_entry_get_text(GTK_ENTRY(userData.gameApplication->gameContainer.entry_message));
    if (message == NULL || strlen(message) == 0) return;
    sendMessage((char *) message,
                userData.sockFd);
    GtkWidget *gtkLabel = gtk_label_new(message);
    gtk_widget_set_visible(gtkLabel, TRUE);
    gtk_label_set_xalign(GTK_LABEL(gtkLabel), 1);
    gtk_widget_set_halign(gtkLabel, GTK_ALIGN_END);
    gtk_label_set_max_width_chars(GTK_LABEL(gtkLabel), 30);
    gtk_label_set_line_wrap(GTK_LABEL(gtkLabel), TRUE);
    gtk_widget_set_margin_start(gtkLabel, 135);
    GtkCssProvider *provider_game = userData.provider;
    css_set(provider_game, gtkLabel);
    add_class(gtkLabel, "text-send-message");
    add_message(gtkLabel);
    clear_entry_message();
}

void on_add_message_recv(char *message) {
    sleep(1);
    GtkWidget *gtkLabel = gtk_label_new(message);
    gtk_widget_set_visible(gtkLabel, TRUE);
    gtk_label_set_xalign(GTK_LABEL(gtkLabel), 0);
    gtk_widget_set_halign(gtkLabel, GTK_ALIGN_START);
    gtk_label_set_max_width_chars(GTK_LABEL(gtkLabel), 30);
    gtk_label_set_line_wrap(GTK_LABEL(gtkLabel), TRUE);
    gtk_widget_set_margin_end(gtkLabel, 135);
    GtkCssProvider *provider_game = userData.provider;
    css_set(provider_game, gtkLabel);
    add_class(gtkLabel, "text-recv-message");
    add_message(gtkLabel);
}

void on_clicked_game_home(GtkButton *button) {
    gtk_main_quit_game(NULL);
}

void on_clicked_game_redo(GtkButton *button) {
    printf("%s\n", "HandleClickRedoGame");
}

void on_clicked_cell(GtkButton *button) {
    if (userData.isNext == NEXT_NOT_YOU || userData.isNext == END_GAME) return;
    userData.isNext = NEXT_NOT_YOU;
    change_label_next_person();
    remove_class(GTK_WIDGET(button), "no-chose");
    add_class(GTK_WIDGET(button), userData.icon == X_ICON ? "x-chose" : "o-chose");
    gtk_widget_set_can_focus(GTK_WIDGET(button), FALSE);
    const char *name = (const char *) gtk_widget_get_name(GTK_WIDGET(button));

    sendNextGameStatus(name[0], name[1], userData.sockFd);
}

void on_clicked_set_cell(int row, int col) {
    GtkWidget *button = gtk_grid_get_child_at(GTK_GRID(userData.gameApplication->gameContainer.grid_caro), row, col);
    userData.isNext = NEXT_YOU;
    change_label_next_person();
    remove_class(button, "no-chose");
    printf("Ho chon : %s\n", userData.icon == X_ICON ? "o-chose" : "x-chose");
    add_class(GTK_WIDGET(button), userData.icon == X_ICON ? "o-chose" : "x-chose");
    gtk_widget_set_can_focus(GTK_WIDGET(button), FALSE);
}

void set_win_cell(int row, int col, int tag) {
    GtkWidget *button = gtk_grid_get_child_at(GTK_GRID(userData.gameApplication->gameContainer.grid_caro), row, col);
    if(userData.isNext != END_GAME) userData.isNext = NEXT_YOU;
    change_label_next_person();
    if (tag == 2) {
        remove_class(button, userData.icon == X_ICON ? "x-chose" : "o-chose");
        add_class(button, userData.icon == X_ICON ? "x-win" : "o-win");
    } else {
        remove_class(button, userData.icon == X_ICON ? "o-chose" : "x-chose");
        add_class(button, userData.icon == X_ICON ? "o-win" : "x-win");
    }
}


void set_label_status_game(char *status) {
    gtk_label_set_text(GTK_LABEL(userData.gameApplication->gameContainer.lbl_status_game), status);
}

