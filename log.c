#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

static FILE *logfile;

static void
open_logfile(void)
{
	const char *home;
	char buf[4096];

	if (logfile)
		return;

	home = getenv("HOME");
	if (!home)
		return;
	snprintf(buf, sizeof buf, "%s/cwm.log", home);

	logfile = fopen(buf, "w");
	if (logfile)
		setvbuf(logfile, NULL, _IOLBF, 0);
}

void
write_log(const char *fmt, ...)
{
	va_list ap;

	open_logfile();

	va_start(ap, fmt);
	vfprintf(logfile, fmt, ap);
	va_end(ap);
        fflush(logfile);
}
