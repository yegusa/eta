#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <yaz/yaz-util.h>

#include <yaz/tcpip.h>
#ifdef USE_XTIMOSI
#include <yaz/xmosi.h>
#endif

#include <yaz/proto.h>
#include <yaz/marcdisp.h>
#include <yaz/diagbib1.h>

#include <yaz/pquery.h>

#if YAZ_MODULE_ill
#include <yaz/ill.h>
#endif

#if YAZ_MODULE_ccl
#include <yaz/yaz-ccl.h>
#endif

#if HAVE_READLINE_READLINE_H
#include <readline/readline.h>
#endif
#if HAVE_READLINE_HISTORY_H
#include <readline/history.h>
#endif

extern int cmd_base(char *arg);
extern int cmd_update(char *arg);
extern int cmd_itemorder(char *arg);
extern int cmd_find(char *arg);
extern int cmd_delete(char *arg);
extern int cmd_ssub(char *arg);
extern int cmd_lslb(char *arg);
extern int cmd_mspn(char *arg);
extern int cmd_status(char *arg);
extern int cmd_setnames(char *arg);
extern int cmd_show(char *arg);
