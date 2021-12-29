
#ifndef NETWORKPROGRAM_STYLESCREEN_H
#define NETWORKPROGRAM_STYLESCREEN_H

#include <gtk/gtk.h>

void css_set(GtkCssProvider *provider, GtkWidget *widget);

void add_class(GtkWidget *widget, const char *s_class);

void remove_class(GtkWidget *widget, const char *s_class);

#endif
