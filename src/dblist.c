/*
 * Copyright (C) 2000 Masao Takaku. All rights reserved.
 *
 *  $Id$
 */

#include <stdio.h>
#include <stdlib.h>

#include <libxml/parser.h>
#include <libxml/tree.h>

#include <glib.h>

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

static GSList*
parse_dblistfile(char *filename)
{
    xmlDocPtr doc;
    xmlNodePtr cur;
    dblist *db;
    GSList *ret = NULL;

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
	ret = g_slist_append(ret, db);
	/* print_database(db); */
	cur = cur->next;
    }
    
    
    return(ret);
}

static void
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

static void
dblist_print (gpointer data, gpointer user_data)
{
    dblist *db = (dblist*) data;
    print_database(db);
}

static void
usage(void)
{
    printf("Usage: dblist dblist.xml\n");
}
    
int main (int argc, char *argv[])
{
    GSList *dblist = NULL;

    if (argc < 2) {
	usage();
	exit(0);
    }
    dblist = parse_dblistfile(argv[1]);
    if (dblist == NULL)
	fprintf( stderr, "Error parsing file '%s'\n", argv[1]);

    g_slist_foreach(dblist, dblist_print, NULL);
    return(0);
}
