/*
 * Copyright (C) 2000 Masao Takaku. All rights reserved.
 *
 *  $Id$
 */

#include <stdio.h>
#include <stdlib.h>

#include <libxml/parser.h>
#include <libxml/tree.h>

#include "dblist.h"

dblist*
parse_dblistfile(char *filename)
{
    xmlDocPtr doc;
    xmlNodePtr cur;
    dblist *ret;

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
        fprintf(stderr, "document of the wrong type, root node != dblist");
        xmlFreeDoc(doc);
        return(NULL);
    }

    ret = (dblist *) malloc (sizeof(dblist));
    if (ret == NULL) {
        fprintf(stderr,"out of memory\n");
        return(NULL);
    }

    cur = cur->xmlChildrenNode->xmlChildrenNode;
    while (cur != NULL) {
	if (!strcmp(cur->name, "name")) {
            ret->name = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
	}
	if (!strcmp(cur->name, "url")) {
            ret->url = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
	}
	if (!strcmp(cur->name, "recordsyntax")) {
	    ret->recordsyntax =
		xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
	    
	}
	cur = cur->next;
    }
    
    return(ret);
}

int main (int argc, char *argv[])
{
    dblist *dblist = parse_dblistfile(argv[1]);
    if (dblist != NULL) {
	printf("Name: %s\n", dblist->name);
	printf("URL: %s\n", dblist->url);
	printf("RecordSyntax: %s\n", dblist->recordsyntax);
    } else {
	fprintf( stderr, "Error parsing file '%s'\n", argv[1]);
    }
    return(0);
}
