#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <libxml/parser.h>
#include <libxml/tree.h>

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "z3950.h"
#include "dblist.h"

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
    if (z3950_callback("open", str)) {
	puts("open: failed\n");
    } else {
	window = create_window2();
	gtk_widget_show (window);
    }
}

void
on_clist1_select_row                   (GtkCList        *clist,
                                        gint             row,
                                        gint             column,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{
    dblist *db;
    
    db = gtk_clist_get_row_data(GTK_CLIST(clist), row);
    puts("on_clist_select_row");
    print_database(db);

    gtk_entry_set_text(GTK_ENTRY(user_data), (gchar*) db->url);
}

/*
 * In search window:
 */

void
search_action (gchar* str)
{
    z3950_callback("find", str);
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
on_list2_select_child                  (GtkList         *list,
                                        GtkWidget       *widget,
                                        gpointer         user_data)
{
    /* gtk_entry_set_text(GTK_ENTRY(user_data), ); */
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

