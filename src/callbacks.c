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
    exit(0);

}


void
on_about_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data)
{

}

