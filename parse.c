#include <stdlib.h>
#include <string.h>
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYLEX yylex()
#define YYEMPTY -1
#define yyclearin (yychar=(YYEMPTY))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING() (yyerrflag!=0)
#define YYPREFIX "yy"
#line 23 "parse.y"

#include <sys/param.h>
#include <sys/queue.h>

#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calmwm.h"

TAILQ_HEAD(files, file)		 files = TAILQ_HEAD_INITIALIZER(files);
static struct file {
	TAILQ_ENTRY(file)	 entry;
	FILE			*stream;
	char			*name;
	int			 lineno;
	int			 errors;
} *file;

struct file		*pushfile(const char *);
int			 popfile(void);
int			 yyparse(void);
int			 yylex(void);
int			 yyerror(const char *, ...);
int			 kw_cmp(const void *, const void *);
int			 lookup(char *);
int			 lgetc(int);
int			 lungetc(int);
int			 findeol(void);

static struct conf	*conf;

typedef struct {
	union {
		int64_t			 number;
		char			*string;
	} v;
	int lineno;
} YYSTYPE;

#line 59 "y.tab.c"
#define FONTNAME 257
#define STICKY 258
#define GAP 259
#define MOUSEBIND 260
#define AUTOGROUP 261
#define BIND 262
#define COMMAND 263
#define IGNORE 264
#define YES 265
#define NO 266
#define BORDERWIDTH 267
#define MOVEAMOUNT 268
#define COLOR 269
#define SNAPDIST 270
#define ACTIVEBORDER 271
#define INACTIVEBORDER 272
#define GROUPBORDER 273
#define UNGROUPBORDER 274
#define MENUBG 275
#define MENUFG 276
#define FONTCOLOR 277
#define ERROR 278
#define STRING 279
#define NUMBER 280
#define YYERRCODE 256
#if defined(__cplusplus) || defined(__STDC__)
const short yylhs[] =
#else
short yylhs[] =
#endif
	{                                        -1,
    0,    0,    0,    0,    0,    2,    2,    1,    1,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    4,    5,    5,    5,    5,    5,    5,    5,
};
#if defined(__cplusplus) || defined(__STDC__)
const short yylen[] =
#else
short yylen[] =
#endif
	{                                         2,
    0,    2,    3,    3,    3,    2,    1,    1,    1,    2,
    2,    2,    2,    2,    3,    3,    2,    3,    5,    3,
    2,    2,    2,    2,    2,    2,    2,    2,
};
#if defined(__cplusplus) || defined(__STDC__)
const short yydefred[] =
#else
short yydefred[] =
#endif
	{                                      1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    2,    0,    0,    5,   10,    8,
    9,   11,    0,    0,    0,    0,    0,   17,   12,   13,
    0,    0,    0,    0,    0,    0,    0,   21,   14,    3,
    4,    0,    7,    0,   16,    0,    0,   22,   23,   24,
   25,   26,   27,   28,    0,    6,   19,
};
#if defined(__cplusplus) || defined(__STDC__)
const short yydgoto[] =
#else
short yydgoto[] =
#endif
	{                                       1,
   22,   44,   16,   17,   38,
};
#if defined(__cplusplus) || defined(__STDC__)
const short yysindex[] =
#else
short yysindex[] =
#endif
	{                                      0,
  -10,    2, -266, -257, -265, -263, -262, -260, -259, -258,
 -256, -255, -270, -254,    0,    4,    7,    0,    0,    0,
    0,    0, -253, -251, -250, -251, -251,    0,    0,    0,
 -249, -248, -247, -246, -245, -244, -243,    0,    0,    0,
    0, -242,    0, -240,    0, -240, -240,    0,    0,    0,
    0,    0,    0,    0, -239,    0,    0,};
#if defined(__cplusplus) || defined(__STDC__)
const short yyrindex[] =
#else
short yyrindex[] =
#endif
	{                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   12,    0,    2,   13,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,};
#if defined(__cplusplus) || defined(__STDC__)
const short yygindex[] =
#else
short yygindex[] =
#endif
	{                                      0,
    0,  -16,    0,    0,    0,
};
#define YYTABLESIZE 260
#if defined(__cplusplus) || defined(__STDC__)
const short yytable[] =
#else
short yytable[] =
#endif
	{                                      15,
   31,   32,   33,   34,   35,   36,   37,   20,   21,   46,
   47,   18,   19,   40,   23,   24,   41,   25,   26,   27,
   28,   20,   15,   29,   30,   39,   42,   43,   45,   48,
   49,   50,   51,   52,   53,   54,    0,   55,   56,    0,
   57,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    2,    3,    4,    5,    6,
    7,    8,    9,   10,    0,    0,   11,   12,   13,   14,
};
#if defined(__cplusplus) || defined(__STDC__)
const short yycheck[] =
#else
short yycheck[] =
#endif
	{                                      10,
  271,  272,  273,  274,  275,  276,  277,  265,  266,   26,
   27,   10,  279,   10,  280,  279,   10,  280,  279,  279,
  279,   10,   10,  280,  280,  280,  280,  279,  279,  279,
  279,  279,  279,  279,  279,  279,   -1,  280,  279,   -1,
  280,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  256,  257,  258,  259,  260,
  261,  262,  263,  264,   -1,   -1,  267,  268,  269,  270,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 280
#if YYDEBUG
#if defined(__cplusplus) || defined(__STDC__)
const char * const yyname[] =
#else
char *yyname[] =
#endif
	{
"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"FONTNAME","STICKY","GAP",
"MOUSEBIND","AUTOGROUP","BIND","COMMAND","IGNORE","YES","NO","BORDERWIDTH",
"MOVEAMOUNT","COLOR","SNAPDIST","ACTIVEBORDER","INACTIVEBORDER","GROUPBORDER",
"UNGROUPBORDER","MENUBG","MENUFG","FONTCOLOR","ERROR","STRING","NUMBER",
};
#if defined(__cplusplus) || defined(__STDC__)
const char * const yyrule[] =
#else
char *yyrule[] =
#endif
	{"$accept : grammar",
"grammar :",
"grammar : grammar '\\n'",
"grammar : grammar main '\\n'",
"grammar : grammar color '\\n'",
"grammar : grammar error '\\n'",
"string : string STRING",
"string : STRING",
"yesno : YES",
"yesno : NO",
"main : FONTNAME STRING",
"main : STICKY yesno",
"main : BORDERWIDTH NUMBER",
"main : MOVEAMOUNT NUMBER",
"main : SNAPDIST NUMBER",
"main : COMMAND STRING string",
"main : AUTOGROUP NUMBER STRING",
"main : IGNORE STRING",
"main : BIND STRING string",
"main : GAP NUMBER NUMBER NUMBER NUMBER",
"main : MOUSEBIND STRING string",
"color : COLOR colors",
"colors : ACTIVEBORDER STRING",
"colors : INACTIVEBORDER STRING",
"colors : GROUPBORDER STRING",
"colors : UNGROUPBORDER STRING",
"colors : MENUBG STRING",
"colors : MENUFG STRING",
"colors : FONTCOLOR STRING",
};
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH 10000
#endif
#endif
#define YYINITSTACKSIZE 200
/* LINTUSED */
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short *yyss;
short *yysslim;
YYSTYPE *yyvs;
int yystacksize;
#line 202 "parse.y"

struct keywords {
	const char	*k_name;
	int		 k_val;
};

int
yyerror(const char *fmt, ...)
{
	va_list ap;

	file->errors++;
	va_start(ap, fmt);
	fprintf(stderr, "%s:%d: ", file->name, yylval.lineno);
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");
	va_end(ap);
	return (0);
}

int
kw_cmp(const void *k, const void *e)
{
	return (strcmp(k, ((const struct keywords *)e)->k_name));
}

int
lookup(char *s)
{
	/* this has to be sorted always */
	static const struct keywords keywords[] = {
		{ "activeborder",	ACTIVEBORDER},
		{ "autogroup",		AUTOGROUP},
		{ "bind",		BIND},
		{ "borderwidth",	BORDERWIDTH},
		{ "color",		COLOR},
		{ "command",		COMMAND},
		{ "font",		FONTCOLOR},
		{ "fontname",		FONTNAME},
		{ "gap",		GAP},
		{ "groupborder",	GROUPBORDER},
		{ "ignore",		IGNORE},
		{ "inactiveborder",	INACTIVEBORDER},
		{ "menubg",		MENUBG},
		{ "menufg",		MENUFG},
		{ "mousebind",		MOUSEBIND},
		{ "moveamount",		MOVEAMOUNT},
		{ "no",			NO},
		{ "snapdist",		SNAPDIST},
		{ "sticky",		STICKY},
		{ "ungroupborder",	UNGROUPBORDER},
		{ "yes",		YES}
	};
	const struct keywords	*p;

	p = bsearch(s, keywords, sizeof(keywords)/sizeof(keywords[0]),
	    sizeof(keywords[0]), kw_cmp);

	if (p)
		return (p->k_val);
	else
		return (STRING);
}

#define MAXPUSHBACK	128

char	*parsebuf;
int	 parseindex;
char	 pushback_buffer[MAXPUSHBACK];
int	 pushback_index = 0;

int
lgetc(int quotec)
{
	int		c, next;

	if (parsebuf) {
		/* Read character from the parsebuffer instead of input. */
		if (parseindex >= 0) {
			c = parsebuf[parseindex++];
			if (c != '\0')
				return (c);
			parsebuf = NULL;
		} else
			parseindex++;
	}

	if (pushback_index)
		return (pushback_buffer[--pushback_index]);

	if (quotec) {
		if ((c = getc(file->stream)) == EOF) {
			yyerror("reached end of file while parsing quoted string");
			if (popfile() == EOF)
				return (EOF);
			return (quotec);
		}
		return (c);
	}

	while ((c = getc(file->stream)) == '\\') {
		next = getc(file->stream);
		if (next != '\n') {
			c = next;
			break;
		}
		yylval.lineno = file->lineno;
		file->lineno++;
	}

	while (c == EOF) {
		if (popfile() == EOF)
			return (EOF);
		c = getc(file->stream);
	}
	return (c);
}

int
lungetc(int c)
{
	if (c == EOF)
		return (EOF);
	if (parsebuf) {
		parseindex--;
		if (parseindex >= 0)
			return (c);
	}
	if (pushback_index < MAXPUSHBACK-1)
		return (pushback_buffer[pushback_index++] = c);
	else
		return (EOF);
}

int
findeol(void)
{
	int	c;

	parsebuf = NULL;
	pushback_index = 0;

	/* skip to either EOF or the first real EOL */
	while (1) {
		c = lgetc(0);
		if (c == '\n') {
			file->lineno++;
			break;
		}
		if (c == EOF)
			break;
	}
	return (ERROR);
}

int
yylex(void)
{
	char	 buf[8096];
	char	*p;
	int	 quotec, next, c;
	int	 token;

	p = buf;
	while ((c = lgetc(0)) == ' ' || c == '\t')
		; /* nothing */

	yylval.lineno = file->lineno;
	if (c == '#')
		while ((c = lgetc(0)) != '\n' && c != EOF)
			; /* nothing */

	switch (c) {
	case '\'':
	case '"':
		quotec = c;
		while (1) {
			if ((c = lgetc(quotec)) == EOF)
				return (0);
			if (c == '\n') {
				file->lineno++;
				continue;
			} else if (c == '\\') {
				if ((next = lgetc(quotec)) == EOF)
					return (0);
				if (next == quotec || c == ' ' || c == '\t')
					c = next;
				else if (next == '\n') {
					file->lineno++;
					continue;
				} else
					lungetc(next);
			} else if (c == quotec) {
				*p = '\0';
				break;
			}
			if (p + 1 >= buf + sizeof(buf) - 1) {
				yyerror("string too long");
				return (findeol());
			}
			*p++ = (char)c;
		}
		yylval.v.string = xstrdup(buf);
		return (STRING);
	}

#define allowed_to_end_number(x) \
	(isspace(x) || x == ')' || x ==',' || x == '/' || x == '}' || x == '=')

	if (c == '-' || isdigit(c)) {
		do {
			*p++ = c;
			if ((unsigned)(p-buf) >= sizeof(buf)) {
				yyerror("string too long");
				return (findeol());
			}
		} while ((c = lgetc(0)) != EOF && isdigit(c));
		lungetc(c);
		if (p == buf + 1 && buf[0] == '-')
			goto nodigits;
		if (c == EOF || allowed_to_end_number(c)) {
			const char *errstr = NULL;

			*p = '\0';
			yylval.v.number = strtonum(buf, LLONG_MIN,
			    LLONG_MAX, &errstr);
			if (errstr) {
				yyerror("\"%s\" invalid number: %s",
				    buf, errstr);
				return (findeol());
			}
			return (NUMBER);
		} else {
nodigits:
			while (p > buf + 1)
				lungetc(*--p);
			c = *--p;
			if (c == '-')
				return (c);
		}
	}

#define allowed_in_string(x) \
	(isalnum(x) || (ispunct(x) && x != '(' && x != ')' && \
	x != '{' && x != '}' && x != '<' && x != '>' && \
	x != '!' && x != '=' && x != '#' && x != ','))

	if (isalnum(c) || c == ':' || c == '_' || c == '*' || c == '/') {
		do {
			*p++ = c;
			if ((unsigned)(p-buf) >= sizeof(buf)) {
				yyerror("string too long");
				return (findeol());
			}
		} while ((c = lgetc(0)) != EOF && (allowed_in_string(c)));
		lungetc(c);
		*p = '\0';
		if ((token = lookup(buf)) == STRING)
			yylval.v.string = xstrdup(buf);
		return (token);
	}
	if (c == '\n') {
		yylval.lineno = file->lineno;
		file->lineno++;
	}
	if (c == EOF)
		return (0);
	return (c);
}

struct file *
pushfile(const char *name)
{
	struct file	*nfile;

	nfile = xcalloc(1, sizeof(struct file));
	nfile->name = xstrdup(name);

	if ((nfile->stream = fopen(nfile->name, "r")) == NULL) {
		free(nfile->name);
		free(nfile);
		return (NULL);
	}
	nfile->lineno = 1;
	TAILQ_INSERT_TAIL(&files, nfile, entry);
	return (nfile);
}

int
popfile(void)
{
	struct file	*prev;

	if ((prev = TAILQ_PREV(file, files, entry)) != NULL) {
		prev->errors += file->errors;
		TAILQ_REMOVE(&files, file, entry);
		fclose(file->stream);
		free(file->name);
		free(file);
		file = prev;
		return (0);
	}
	return (EOF);
}

int
parse_config(const char *filename, struct conf *xconf)
{
	int			 errors = 0;

	conf = xcalloc(1, sizeof(*conf));

	if ((file = pushfile(filename)) == NULL) {
		free(conf);
		return (-1);
	}

	(void)strlcpy(conf->conf_path, filename, sizeof(conf->conf_path));

	conf_init(conf);

	yyparse();
	errors = file->errors;
	file->errors = 0;
	popfile();

	if (errors) {
		conf_clear(conf);
	}
	else {
		struct autogroupwin	*ag;
		struct keybinding	*kb;
		struct winmatch		*wm;
		struct cmd		*cmd;
		struct mousebinding	*mb;
		int			 i;

		conf_clear(xconf);

		xconf->flags = conf->flags;
		xconf->bwidth = conf->bwidth;
		xconf->mamount = conf->mamount;
		xconf->snapdist = conf->snapdist;
		xconf->gap = conf->gap;

		while ((cmd = TAILQ_FIRST(&conf->cmdq)) != NULL) {
			TAILQ_REMOVE(&conf->cmdq, cmd, entry);
			TAILQ_INSERT_TAIL(&xconf->cmdq, cmd, entry);
		}

		while ((kb = TAILQ_FIRST(&conf->keybindingq)) != NULL) {
			TAILQ_REMOVE(&conf->keybindingq, kb, entry);
			TAILQ_INSERT_TAIL(&xconf->keybindingq, kb, entry);
		}

		while ((ag = TAILQ_FIRST(&conf->autogroupq)) != NULL) {
			TAILQ_REMOVE(&conf->autogroupq, ag, entry);
			TAILQ_INSERT_TAIL(&xconf->autogroupq, ag, entry);
		}

		while ((wm = TAILQ_FIRST(&conf->ignoreq)) != NULL) {
			TAILQ_REMOVE(&conf->ignoreq, wm, entry);
			TAILQ_INSERT_TAIL(&xconf->ignoreq, wm, entry);
		}

		while ((mb = TAILQ_FIRST(&conf->mousebindingq)) != NULL) {
			TAILQ_REMOVE(&conf->mousebindingq, mb, entry);
			TAILQ_INSERT_TAIL(&xconf->mousebindingq, mb, entry);
		}

		(void)strlcpy(xconf->termpath, conf->termpath,
		    sizeof(xconf->termpath));
		(void)strlcpy(xconf->lockpath, conf->lockpath,
		    sizeof(xconf->lockpath));

		for (i = 0; i < CWM_COLOR_MAX; i++)
			xconf->color[i].name = conf->color[i].name;

		xconf->font = conf->font;
	}

	free(conf);

	return (errors ? -1 : 0);
}
#line 643 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
#if defined(__cplusplus) || defined(__STDC__)
static int yygrowstack(void)
#else
static int yygrowstack()
#endif
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;
    i = yyssp - yyss;
#ifdef SIZE_MAX
#define YY_SIZE_MAX SIZE_MAX
#else
#define YY_SIZE_MAX 0xffffffffU
#endif
    if (newsize && YY_SIZE_MAX / newsize < sizeof *newss)
        goto bail;
    newss = yyss ? (short *)realloc(yyss, newsize * sizeof *newss) :
      (short *)malloc(newsize * sizeof *newss); /* overflow check above */
    if (newss == NULL)
        goto bail;
    yyss = newss;
    yyssp = newss + i;
    if (newsize && YY_SIZE_MAX / newsize < sizeof *newvs)
        goto bail;
    newvs = yyvs ? (YYSTYPE *)realloc(yyvs, newsize * sizeof *newvs) :
      (YYSTYPE *)malloc(newsize * sizeof *newvs); /* overflow check above */
    if (newvs == NULL)
        goto bail;
    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
bail:
    if (yyss)
            free(yyss);
    if (yyvs)
            free(yyvs);
    yyss = yyssp = NULL;
    yyvs = yyvsp = NULL;
    yystacksize = 0;
    return -1;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
#if defined(__cplusplus) || defined(__STDC__)
yyparse(void)
#else
yyparse()
#endif
{
    int yym, yyn, yystate;
#if YYDEBUG
#if defined(__cplusplus) || defined(__STDC__)
    const char *yys;
#else /* !(defined(__cplusplus) || defined(__STDC__)) */
    char *yys;
#endif /* !(defined(__cplusplus) || defined(__STDC__)) */

    if ((yys = getenv("YYDEBUG")))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif /* YYDEBUG */

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#if defined(lint) || defined(__GNUC__)
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#if defined(lint) || defined(__GNUC__)
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 5:
#line 88 "parse.y"
{ file->errors++; }
break;
case 6:
#line 91 "parse.y"
{
			if (asprintf(&yyval.v.string, "%s %s", yyvsp[-1].v.string, yyvsp[0].v.string) == -1) {
				free(yyvsp[-1].v.string);
				free(yyvsp[0].v.string);
				yyerror("string: asprintf");
				YYERROR;
			}
			free(yyvsp[-1].v.string);
			free(yyvsp[0].v.string);
		}
break;
case 8:
#line 104 "parse.y"
{ yyval.v.number = 1; }
break;
case 9:
#line 105 "parse.y"
{ yyval.v.number = 0; }
break;
case 10:
#line 108 "parse.y"
{
			free(conf->font);
			conf->font = yyvsp[0].v.string;
		}
break;
case 11:
#line 112 "parse.y"
{
			if (yyvsp[0].v.number == 0)
				conf->flags &= ~CONF_STICKY_GROUPS;
			else
				conf->flags |= CONF_STICKY_GROUPS;
		}
break;
case 12:
#line 118 "parse.y"
{
			conf->bwidth = yyvsp[0].v.number;
		}
break;
case 13:
#line 121 "parse.y"
{
			conf->mamount = yyvsp[0].v.number;
		}
break;
case 14:
#line 124 "parse.y"
{
			conf->snapdist = yyvsp[0].v.number;
		}
break;
case 15:
#line 127 "parse.y"
{
			conf_cmd_add(conf, yyvsp[0].v.string, yyvsp[-1].v.string, 0);
			free(yyvsp[-1].v.string);
			free(yyvsp[0].v.string);
		}
break;
case 16:
#line 132 "parse.y"
{
			if (yyvsp[-1].v.number < 0 || yyvsp[-1].v.number > 9) {
				free(yyvsp[0].v.string);
				yyerror("autogroup number out of range: %d", yyvsp[-1].v.number);
				YYERROR;
			}

			group_make_autogroup(conf, yyvsp[0].v.string, yyvsp[-1].v.number);
			free(yyvsp[0].v.string);
		}
break;
case 17:
#line 142 "parse.y"
{
			struct winmatch	*wm;

			wm = xcalloc(1, sizeof(*wm));
			(void)strlcpy(wm->title, yyvsp[0].v.string, sizeof(wm->title));
			TAILQ_INSERT_TAIL(&conf->ignoreq, wm, entry);

			free(yyvsp[0].v.string);
		}
break;
case 18:
#line 151 "parse.y"
{
			conf_bindname(conf, yyvsp[-1].v.string, yyvsp[0].v.string);
			free(yyvsp[-1].v.string);
			free(yyvsp[0].v.string);
		}
break;
case 19:
#line 156 "parse.y"
{
			conf->gap.top = yyvsp[-3].v.number;
			conf->gap.bottom = yyvsp[-2].v.number;
			conf->gap.left = yyvsp[-1].v.number;
			conf->gap.right = yyvsp[0].v.number;
		}
break;
case 20:
#line 162 "parse.y"
{
			conf_mousebind(conf, yyvsp[-1].v.string, yyvsp[0].v.string);
			free(yyvsp[-1].v.string);
			free(yyvsp[0].v.string);
		}
break;
case 22:
#line 172 "parse.y"
{
			free(conf->color[CWM_COLOR_BORDER_ACTIVE].name);
			conf->color[CWM_COLOR_BORDER_ACTIVE].name = yyvsp[0].v.string;
		}
break;
case 23:
#line 176 "parse.y"
{
			free(conf->color[CWM_COLOR_BORDER_INACTIVE].name);
			conf->color[CWM_COLOR_BORDER_INACTIVE].name = yyvsp[0].v.string;
		}
break;
case 24:
#line 180 "parse.y"
{
			free(conf->color[CWM_COLOR_BORDER_GROUP].name);
			conf->color[CWM_COLOR_BORDER_GROUP].name = yyvsp[0].v.string;
		}
break;
case 25:
#line 184 "parse.y"
{
			free(conf->color[CWM_COLOR_BORDER_UNGROUP].name);
			conf->color[CWM_COLOR_BORDER_UNGROUP].name = yyvsp[0].v.string;
		}
break;
case 26:
#line 188 "parse.y"
{
			free(conf->color[CWM_COLOR_BG_MENU].name);
			conf->color[CWM_COLOR_BG_MENU].name = yyvsp[0].v.string;
		}
break;
case 27:
#line 192 "parse.y"
{
			free(conf->color[CWM_COLOR_FG_MENU].name);
			conf->color[CWM_COLOR_FG_MENU].name = yyvsp[0].v.string;
		}
break;
case 28:
#line 196 "parse.y"
{
			free(conf->color[CWM_COLOR_FONT].name);
			conf->color[CWM_COLOR_FONT].name = yyvsp[0].v.string;
		}
break;
#line 1014 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    if (yyss)
            free(yyss);
    if (yyvs)
            free(yyvs);
    yyss = yyssp = NULL;
    yyvs = yyvsp = NULL;
    yystacksize = 0;
    return (1);
yyaccept:
    if (yyss)
            free(yyss);
    if (yyvs)
            free(yyvs);
    yyss = yyssp = NULL;
    yyvs = yyvsp = NULL;
    yystacksize = 0;
    return (0);
}
