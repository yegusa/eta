#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "z3950.h"

static void exit_confirm (void);
static void connect_action (gchar*);
static void search_action (gchar*);

/*
 * In connect window:
 */

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
    g_print("on_button1_clicked: %s\n",
	    gtk_entry_get_text(GTK_ENTRY(user_data)));
    
    connect_action(gtk_entry_get_text(GTK_ENTRY(user_data)));
}

void
on_entry1_activate                     (GtkEditable     *editable,
                                        gpointer         user_data)
{

    connect_action(gtk_entry_get_text(GTK_ENTRY(editable)));
}

void
connect_action (gchar* str)
{
    GtkWidget* window;
    if (! cmd_open(str)) {
	puts("cmd_open: failed\n");
    } else {
	window = create_window2();
	gtk_widget_show (window);
    }
}

/*
 * In search window:
 */

void
search_action (gchar* str)
{
    cmd_find(str);
}

void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
    g_print("on_button2_clicked: %s\n",
	    gtk_entry_get_text(GTK_ENTRY(user_data)));

    search_action(gtk_entry_get_text(GTK_ENTRY(user_data)));
}

void
on_entry2_activate                     (GtkEditable     *editable,
                                        gpointer         user_data)
{
    search_action(gtk_entry_get_text(GTK_ENTRY(editable)));
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

