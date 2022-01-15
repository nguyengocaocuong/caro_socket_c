#include "styleScreen.h"

void css_set(GtkCssProvider *provider, GtkWidget *widget) {
    gtk_style_context_add_provider(gtk_widget_get_style_context(widget), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
}
void add_class(GtkWidget *widget, const char *s_class) {
    gtk_style_context_add_class(gtk_widget_get_style_context(widget), s_class);
}
void remove_class(GtkWidget *widget, const char *s_class) {
    gtk_style_context_remove_class(gtk_widget_get_style_context(widget), s_class);
}
