#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"


void
on_exit_activate                       (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{
    /* exit_confirm();*/
    gtk_main_quit();
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
