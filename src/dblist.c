/*
 * Copyright (C) 2000 Masao Takaku. All rights reserved.
 *
 *  $Id$
 */

#include <stdio.h>
#include <stdlib.h>

#include <libxml/parser.h>
#include <libxml/tree.h>

#include <gtk/gtk.h>

#include "dblist.h"

static dblist*
parse_database (xmlDocPtr doc, xmlNodePtr cur)
{
    dblist* db = NULL;
    db = (dblist *) malloc (sizeof(dblist));
    if (db == NULL) {
	fprintf(stderr,"out of memory\n");
	return(NULL);
    }
    while (cur != NULL) {
	if (!xmlStrcmp(cur->name, (const guchar *)"name")) {
	    db->name = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
	}
	if (!xmlStrcmp(cur->name, (const guchar *)"url")) {
	    db->url = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
	}
	if (!xmlStrcmp(cur->name, (const guchar *)"recordsyntax")) {
	    db->recordsyntax =
		xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
	}
	cur = cur->next;
    }
    return(db);
}

GList*
parse_dblistfile(char *filename)
{
    xmlDocPtr doc;
    xmlNodePtr cur;
    dblist *db;
    GList *ret = NULL;

    /*
     * build an XML tree from a the file;
     */
    doc = xmlParseFile(filename);
    if (doc == NULL) return(NULL);

    /*
     * Check the document is of the right kind
     */
    cur = xmlDocGetRootElement(doc);
    if (cur == NULL) {
        fprintf(stderr,"empty document\n");
        xmlFreeDoc(doc);
        return(NULL);
    }

    if (xmlStrcmp(cur->name, (const xmlChar *) "dblist")) {
        fprintf(stderr, "document of the wrong type, root node != dblist\n");
        xmlFreeDoc(doc);
        return(NULL);
    }

    cur = cur->xmlChildrenNode;
    while (cur != NULL) {
	if (xmlStrcmp(cur->name, (const xmlChar *) "database")) {
	    fprintf(stderr, "document of the wrong type, root node != database\n");
	    xmlFreeDoc(doc);
	    return(NULL);
	}
	db = parse_database(doc, cur->xmlChildrenNode);
	ret = g_list_append(ret, db);
	/* print_database(db); */
	cur = cur->next;
    }
    
    return(ret);
}

void
print_database (dblist *db)
{
    if (db != NULL) {
	puts("--");
	printf("Name: %s\n", db->name);
	printf("URL: %s\n", db->url);
	printf("RecordSyntax: %s\n", db->recordsyntax);
    } else {
	fprintf(stderr, "database is NULL\n");
    }
}

void
print_dblist (gpointer data, gpointer user_data)
{
    dblist *db = (dblist*) data;
    print_database(db);
}

/*
 * Set text and data for list of Z39.50 databases.
 */
void dblist_append (GList *list, GtkWidget *clist)
{
    int i;
    gchar *text[] = {0};
    for (i = 0; list != NULL; i++, list = list->next) {
	text[0] = (gchar *) ((dblist*) (list->data))->name;
	gtk_clist_append(GTK_CLIST(clist), text);
	gtk_clist_set_row_data(GTK_CLIST(clist), i, list->data);
    }
}

#ifdef DEBUG
int main (int argc, char *argv[])
{
    GList *dblist = NULL;

    if (argc < 2) {
	usage();
	exit(0);
    }
    dblist = parse_dblistfile(argv[1]);
    if (dblist == NULL)
	fprintf( stderr, "Error parsing file '%s'\n", argv[1]);

    g_list_foreach(dblist, dblist_print, NULL);
    return(0);
}

static void
usage(void)
{
    printf("Usage: dblist dblist.xml\n");
}
#endif
