/*
 * Copyright (C) 2000 Masao Takaku. All rights reserved.
 */

typedef struct dblist {
    xmlChar *name;
    xmlChar *url;
    xmlChar *recordsyntax;
} dblist;

GList* parse_dblistfile(char *filename);
void print_database (dblist *db);
void dblist_append (GList *list, GtkWidget *clist);
