#include "initScreen.h"
#include "styleScreen.h"


void initHomeScreen() {
    GtkBuilder *builder = gtk_builder_new_from_file("screen/home.glade");

    userData.gameApplication->homeContainer.window_home = (GtkWidget *) gtk_builder_get_object(builder, "window_home");
    userData.gameApplication->homeContainer.btn_login = (GtkWidget *) gtk_builder_get_object(builder, "login");
    userData.gameApplication->homeContainer.btn_register = (GtkWidget *) gtk_builder_get_object(builder, "register");

    g_signal_connect(userData.gameApplication->homeContainer.window_home, "destroy", G_CALLBACK(gtk_main_quit_home),NULL);
    g_signal_connect(userData.gameApplication->homeContainer.btn_login, "clicked", G_CALLBACK(on_login_clicked),
                     NULL);
    g_signal_connect(userData.gameApplication->homeContainer.btn_register, "clicked", G_CALLBACK(on_register_clicked),
                     NULL);

    GtkCssProvider *provider = gtk_css_provider_new();

    gtk_css_provider_load_from_path(provider, "style/home.css", NULL);
    css_set(provider, (GtkWidget *) userData.gameApplication->homeContainer.btn_login);
    css_set(provider, (GtkWidget *) userData.gameApplication->homeContainer.btn_register);
    css_set(provider, (GtkWidget *) userData.gameApplication->homeContainer.window_home);
}

void initLoginScreen() {
    GtkBuilder *builder = gtk_builder_new_from_file("screen/login.glade");
    userData.gameApplication->loginContainer.window_login = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                 "window_login");
    userData.gameApplication->loginContainer.btn_sign_in = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                "btn_sign_in");
    userData.gameApplication->loginContainer.btn_back = (GtkWidget *) gtk_builder_get_object(builder, "btn_back");
    userData.gameApplication->loginContainer.btn_reset_pass = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                   "btn_reset_pass");
    userData.gameApplication->loginContainer.lbl_error = (GtkWidget *) gtk_builder_get_object(builder, "lbl_error");
    userData.gameApplication->loginContainer.entry_pass = (GtkWidget *) gtk_builder_get_object(builder, "entry_pass");
    userData.gameApplication->loginContainer.entry_account = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                  "entry_account");

    GtkCssProvider *provider_login = gtk_css_provider_new();

    gtk_css_provider_load_from_path(provider_login, "style/login.css", NULL);
    css_set(provider_login, (GtkWidget *) userData.gameApplication->loginContainer.window_login);
    css_set(provider_login, (GtkWidget *) userData.gameApplication->loginContainer.btn_sign_in);
    css_set(provider_login, (GtkWidget *) userData.gameApplication->loginContainer.btn_back);
    css_set(provider_login, (GtkWidget *) userData.gameApplication->loginContainer.btn_reset_pass);
    css_set(provider_login, (GtkWidget *) userData.gameApplication->loginContainer.lbl_error);
    css_set(provider_login, (GtkWidget *) userData.gameApplication->loginContainer.entry_pass);
    css_set(provider_login, (GtkWidget *) userData.gameApplication->loginContainer.entry_account);

    g_signal_connect(userData.gameApplication->loginContainer.window_login, "destroy", G_CALLBACK(gtk_main_quit_login),
                     NULL);
    g_signal_connect(userData.gameApplication->loginContainer.btn_back, "clicked", G_CALLBACK(on_back_clicked),
                     NULL);
    g_signal_connect(userData.gameApplication->loginContainer.btn_sign_in, "clicked", G_CALLBACK(on_sign_in_clicked),
                     NULL);
}

void initRegisterScreen() {
    GtkBuilder *builder = gtk_builder_new_from_file("screen/register.glade");
    userData.gameApplication->registerContainer.window_register = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                       "window_register");
    userData.gameApplication->registerContainer.btn_register = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                    "btn_register_rs");
    userData.gameApplication->registerContainer.btn_back = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                "btn_back_rs");
    userData.gameApplication->registerContainer.lbl_error = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                 "lbl_error_rs");
    userData.gameApplication->registerContainer.entry_pass = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                  "entry_pass_rs");
    userData.gameApplication->registerContainer.entry_account = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                     "entry_account_rs");
    userData.gameApplication->registerContainer.entry_confirm_pass = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                          "entry_confirm_pass");


    GtkCssProvider *provider_register = gtk_css_provider_new();
    gtk_css_provider_load_from_path(provider_register, "style/register.css", NULL);

    css_set(provider_register, (GtkWidget *) userData.gameApplication->registerContainer.window_register);
    css_set(provider_register, (GtkWidget *) userData.gameApplication->registerContainer.btn_register);
    css_set(provider_register, (GtkWidget *) userData.gameApplication->registerContainer.btn_back);
    css_set(provider_register, (GtkWidget *) userData.gameApplication->registerContainer.entry_confirm_pass);
    css_set(provider_register, (GtkWidget *) userData.gameApplication->registerContainer.lbl_error);
    css_set(provider_register, (GtkWidget *) userData.gameApplication->registerContainer.entry_pass);
    css_set(provider_register, (GtkWidget *) userData.gameApplication->registerContainer.entry_account);

    g_signal_connect(userData.gameApplication->registerContainer.window_register, "destroy",
                     G_CALLBACK(gtk_main_quit_rs_login), NULL);
    g_signal_connect(userData.gameApplication->registerContainer.btn_back, "clicked", G_CALLBACK(on_back_rs_clicked),
                     NULL);
    g_signal_connect(userData.gameApplication->registerContainer.btn_register, "clicked",
                     G_CALLBACK(on_register_rs_clicked),NULL);
}

void initGameScreen() {
    GtkBuilder *builder = gtk_builder_new_from_file("screen/game.glade");
    userData.gameApplication->gameContainer.window_game = (GtkWidget *) gtk_builder_get_object(builder, "window_game");
    userData.gameApplication->gameContainer.btn_redo = (GtkWidget *) gtk_builder_get_object(builder, "btn_redo");
    userData.gameApplication->gameContainer.btn_undo = (GtkWidget *) gtk_builder_get_object(builder, "btn_undo");
    userData.gameApplication->gameContainer.btn_send = (GtkWidget *) gtk_builder_get_object(builder, "btn_send");
    userData.gameApplication->gameContainer.btn_home = (GtkWidget *) gtk_builder_get_object(builder, "btn_home");
    userData.gameApplication->gameContainer.entry_message = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                 "entry_message");
    userData.gameApplication->gameContainer.box_message = (GtkWidget *) gtk_builder_get_object(builder, "box_message");
    userData.gameApplication->gameContainer.lbl_status_game = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                   "lbl_status_game");
    userData.gameApplication->gameContainer.box_notify = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                 "box_notify");
    userData.gameApplication->gameContainer.lbl_next_person = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                   "lbl_next_person");
    userData.gameApplication->gameContainer.grid_caro = (GtkWidget *) gtk_builder_get_object(builder, "grid_caro");
    userData.gameApplication->gameContainer.fixed_caro = (GtkWidget *) gtk_builder_get_object(builder, "fixed_caro");
    userData.gameApplication->gameContainer.fixed_main = (GtkWidget *) gtk_builder_get_object(builder, "fixed_main");
    userData.gameApplication->gameContainer.scroll = (GtkWidget *) gtk_builder_get_object(builder, "scroll");

    GtkCssProvider *provider_game = gtk_css_provider_new();
    userData.provider = provider_game;
    gtk_css_provider_load_from_path(provider_game, "style/game.css", NULL);
    char name[3];
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            GtkWidget *button = gtk_button_new();
            css_set(provider_game, button);
            add_class(button, "no-chose");
            name[0] = (char) ('0' + i);
            name[1] = (char) ('0' + j);
            name[2] = '\0';
            gtk_widget_set_name(button, name);
            gtk_widget_set_visible(button,TRUE);
            g_signal_connect(button, "clicked", G_CALLBACK(on_clicked_cell),NULL);
            gtk_grid_attach(GTK_GRID(userData.gameApplication->gameContainer.grid_caro), button, i, j, 1, 1);
        }
    }

    gtk_builder_connect_signals(builder, NULL);
    css_set(provider_game, (GtkWidget *) userData.gameApplication->gameContainer.window_game);
    css_set(provider_game, (GtkWidget *) userData.gameApplication->gameContainer.btn_redo);
    css_set(provider_game, (GtkWidget *) userData.gameApplication->gameContainer.btn_undo);
    css_set(provider_game, (GtkWidget *) userData.gameApplication->gameContainer.btn_send);
    css_set(provider_game, (GtkWidget *) userData.gameApplication->gameContainer.btn_home);
    css_set(provider_game, (GtkWidget *) userData.gameApplication->gameContainer.entry_message);
    css_set(provider_game, (GtkWidget *) userData.gameApplication->gameContainer.lbl_status_game);
    css_set(provider_game, (GtkWidget *) userData.gameApplication->gameContainer.box_message);
    css_set(provider_game, (GtkWidget *) userData.gameApplication->gameContainer.lbl_next_person);
    css_set(provider_game, (GtkWidget *) userData.gameApplication->gameContainer.grid_caro);
    css_set(provider_game, (GtkWidget *) userData.gameApplication->gameContainer.fixed_main);
    css_set(provider_game, (GtkWidget *) userData.gameApplication->gameContainer.fixed_caro);
    css_set(provider_game, (GtkWidget *) userData.gameApplication->gameContainer.scroll);

    g_signal_connect(userData.gameApplication->gameContainer.window_game, "destroy", G_CALLBACK(gtk_main_quit_game),
                     NULL);
    g_signal_connect(userData.gameApplication->gameContainer.btn_undo, "clicked", G_CALLBACK(on_clicked_game_undo),
                     NULL);
    g_signal_connect(userData.gameApplication->gameContainer.btn_send, "clicked", G_CALLBACK(on_clicked_game_send),
                     NULL);
    g_signal_connect(userData.gameApplication->gameContainer.btn_redo, "clicked", G_CALLBACK(on_clicked_game_redo),
                     NULL);
    g_signal_connect(userData.gameApplication->gameContainer.btn_home, "clicked", G_CALLBACK(on_clicked_game_home),
                     NULL);
}

void initMainScreen() {
    GtkBuilder *builder = gtk_builder_new_from_file("screen/main.glade");

    userData.gameApplication->mainContainer.window_main = (GtkWidget *) gtk_builder_get_object(builder, "window_main");
    userData.gameApplication->mainContainer.btn_new_game = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                "btn_new_game");
    userData.gameApplication->mainContainer.stack_main = (GtkWidget *) gtk_builder_get_object(builder, "stack_main");
    userData.gameApplication->mainContainer.btn_history = (GtkWidget *) gtk_builder_get_object(builder, "btn_history");
    userData.gameApplication->mainContainer.btn_online_account = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                      "btn_online_account");
    userData.gameApplication->mainContainer.btn_home = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                            "btn_home");
    userData.gameApplication->mainContainer.fixed_new_game = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                  "fixed_new_game");
    userData.gameApplication->mainContainer.fixed_main = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                              "fixed_main");
    userData.gameApplication->mainContainer.fixed_history = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                 "fixed_history");
    userData.gameApplication->mainContainer.fixed_online_person = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                       "fixed_online_person");
    userData.gameApplication->mainContainer.box_history = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                               "box_history");
    userData.gameApplication->mainContainer.scroll = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                          "scroll");
    userData.gameApplication->mainContainer.box_online = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                              "box_online");
    userData.gameApplication->mainContainer.box_notify = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                              "box_notify");
    userData.gameApplication->mainContainer.scroll_online = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                 "scroll_online");
    userData.gameApplication->mainContainer.scroll_notify = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                 "scroll_notify");
    userData.gameApplication->mainContainer.start = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                         "btn_start");
    userData.gameApplication->mainContainer.btn_notify = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                              "btn_notify");
    userData.gameApplication->mainContainer.btn_request = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                               "btn_request");
    userData.gameApplication->mainContainer.entry_account = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                 "entry_account");
    userData.gameApplication->mainContainer.fixed_notify = (GtkWidget *) gtk_builder_get_object(builder,
                                                                                                "fixed_notify");

    GtkCssProvider *provider_game = gtk_css_provider_new();
    gtk_css_provider_load_from_path(provider_game, "style/main.css", NULL);
    userData.provider_main = provider_game;
    css_set(provider_game,userData.gameApplication->mainContainer.window_main);
    css_set(provider_game,userData.gameApplication->mainContainer.btn_new_game);
    css_set(provider_game,userData.gameApplication->mainContainer.stack_main);
    css_set(provider_game,userData.gameApplication->mainContainer.btn_history);
    css_set(provider_game,userData.gameApplication->mainContainer.btn_online_account);
    css_set(provider_game,userData.gameApplication->mainContainer.btn_home);
    css_set(provider_game,userData.gameApplication->mainContainer.btn_notify);
    css_set(provider_game,userData.gameApplication->mainContainer.stack_main);
    css_set(provider_game,userData.gameApplication->mainContainer.box_history);
    css_set(provider_game,userData.gameApplication->mainContainer.box_online);
    css_set(provider_game,userData.gameApplication->mainContainer.box_notify);
    css_set(provider_game,userData.gameApplication->mainContainer.scroll);
    css_set(provider_game,userData.gameApplication->mainContainer.scroll_online);
    css_set(provider_game,userData.gameApplication->mainContainer.scroll_notify);
    css_set(provider_game,userData.gameApplication->mainContainer.start);
    css_set(provider_game,userData.gameApplication->mainContainer.btn_request);
    css_set(provider_game,userData.gameApplication->mainContainer.entry_account);
    css_set(provider_game, (GtkWidget *) gtk_builder_get_object(builder, "box_menu"));
    css_set(provider_game, (GtkWidget *) gtk_builder_get_object(builder, "lbel_history"));
    css_set(provider_game, (GtkWidget *) gtk_builder_get_object(builder, "lbel_online"));
    css_set(provider_game, (GtkWidget *) gtk_builder_get_object(builder, "lbel_game"));
    css_set(provider_game, (GtkWidget *) gtk_builder_get_object(builder, "lbel_notify"));


    g_signal_connect(userData.gameApplication->mainContainer.window_main, "destroy", G_CALLBACK(gtk_main_quit_main),
                     NULL);
    g_signal_connect(userData.gameApplication->mainContainer.btn_new_game, "clicked", G_CALLBACK(on_new_game_clicked),
                     NULL);
    g_signal_connect(userData.gameApplication->mainContainer.btn_history, "clicked", G_CALLBACK(on_history_clicked),
                     NULL);
    g_signal_connect(userData.gameApplication->mainContainer.btn_request, "clicked", G_CALLBACK(on_request_clicked),
                     NULL);
    g_signal_connect(userData.gameApplication->mainContainer.btn_online_account, "clicked",
                     G_CALLBACK(on_online_account_clicked),NULL);
    g_signal_connect(userData.gameApplication->mainContainer.btn_home, "clicked",
                     G_CALLBACK(on_home_clicked),NULL);
    g_signal_connect(userData.gameApplication->mainContainer.start, "clicked",
                     G_CALLBACK(on_start_clicked),NULL);
    g_signal_connect(userData.gameApplication->mainContainer.btn_notify, "clicked",
                     G_CALLBACK(on_notify_clicked),NULL);

}

void initApplication() {
    initMainScreen();
    initHomeScreen();
    initLoginScreen();
    initRegisterScreen();
    initGameScreen();
}
