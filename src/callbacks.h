#include <gtk/gtk.h>


void
on_exit_activate                       (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_about_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_file1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_help2_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data);


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_entry1_activate                     (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_entry2_activate                     (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_list2_select_child                  (GtkList         *list,
                                        GtkWidget       *widget,
                                        gpointer         user_data);

void
on_clist1_select_row                   (GtkCList        *clist,
                                        gint             row,
                                        gint             column,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_clist1_select_row                   (GtkCList        *clist,
                                        gint             row,
                                        gint             column,
                                        GdkEvent        *event,
                                        gpointer         user_data);
