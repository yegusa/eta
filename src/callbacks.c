#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "z3950.h"

static void exit_confirm(void);

void
on_exit_activate                       (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
    exit_confirm();
}


void
on_about_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
    
}


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget* window;
    g_print("on_button1_clicked: %s\n",
	    gtk_entry_get_text(GTK_ENTRY(user_data)));
    
    if (! cmd_open(gtk_entry_get_text(GTK_ENTRY(user_data)))) {
	puts("cmd_open: failed\n");
    } else {
	window = create_window2();
	gtk_widget_show (window);
    }
}

void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
    g_print("on_button2_clicked: %s\n",
	    gtk_entry_get_text(GTK_ENTRY(user_data)));

}

void
on_file1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}


void
on_help2_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}

void
exit_confirm(void)
{
    GtkWidget* window = create_window3();
    gtk_widget_show (window);
}
