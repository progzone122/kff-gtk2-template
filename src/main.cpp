#include <gtk-2.0/gtk/gtk.h>
#include "config.hpp"

void set_label_font(GtkWidget *label, const char *font_desc_str) {
    PangoFontDescription *font_desc = pango_font_description_from_string(font_desc_str);
    gtk_widget_modify_font(label, font_desc);
    pango_font_description_free(font_desc);
}

int main(int argc, char* argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request(window, DESKTOP_W_SIZE, DESKTOP_H_SIZE);
    gtk_window_set_title(GTK_WINDOW(window), WINDOW_TITLE);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Содержимое
    GtkWidget *vbox = gtk_vbox_new(FALSE, 5);
    GtkWidget *label1 = gtk_label_new("GTK 2.0 for Kindle is forged!");
    GtkWidget *label2 = gtk_label_new("Generated with love by KFF <3");
    GtkWidget *label3 = gtk_label_new("https://github.com/progzone122/kff");
    GtkWidget *button_exit = gtk_button_new_with_label("Exit and continue forging");


    gtk_box_pack_start(GTK_BOX(vbox), label1, FALSE, FALSE, 0);
    set_label_font(label1, "Sans Bold 20");

    gtk_box_pack_start(GTK_BOX(vbox), label2, FALSE, FALSE, 0);
    set_label_font(label2, "Sans 14");

    gtk_box_pack_start(GTK_BOX(vbox), label3, FALSE, FALSE, 0);
    set_label_font(label3, "Sans 10");

    gtk_box_pack_start(GTK_BOX(vbox), button_exit, FALSE, FALSE, 0);
    g_signal_connect(button_exit, "clicked", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *alignment = gtk_alignment_new(0.5, 0.4, 0, 0);
    gtk_container_add(GTK_CONTAINER(alignment), vbox);

    gtk_container_add(GTK_CONTAINER(window), alignment);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
