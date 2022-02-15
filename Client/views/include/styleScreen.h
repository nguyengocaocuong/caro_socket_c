
#ifndef NETWORKPROGRAM_STYLESCREEN_H
#define NETWORKPROGRAM_STYLESCREEN_H

#include <gtk/gtk.h>
/**
 *
 * @param provider
 * @param widget
 */
void css_set(GtkCssProvider *provider, GtkWidget *widget);
/**
 *
 * @param widget
 * @param s_class
 */
void add_class(GtkWidget *widget, const char *s_class);
/**
 *
 * @param widget
 * @param s_class
 */
void remove_class(GtkWidget *widget, const char *s_class);

#endif
