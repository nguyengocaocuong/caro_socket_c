
#ifndef NETWORKPROGRAM_STYLESCREEN_H
#define NETWORKPROGRAM_STYLESCREEN_H

#include <gtk/gtk.h>
/**
 * Hàm này có chức năng thêm một provider vào một widget
 * @param provider : provider được thêm vào widget
 * @param widget : widget cần thêm
 */
void css_set(GtkCssProvider *provider, GtkWidget *widget);
/**
 * Hàm này thêm một class vào một widget
 * @param widget : widget được thêm class
 * @param s_class : tên class
 */
void add_class(GtkWidget *widget, const char *s_class);
/**
 * Hàm này loại bỏ một class khỏi một widget
 * @param widget : widget được loại bỏ class
 * @param s_class : tên class cần loại bỏ
 */
void remove_class(GtkWidget *widget, const char *s_class);

#endif
