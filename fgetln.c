/*
 * Public domain.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "openbsd.h"

/*
 * http://www.openbsd.org/cgi-bin/man.cgi?query=fgetln
 *
 * This function is used in kbfunc.c to read lines from the known
 * SSH hosts file.
 *
 * It won't work correctly if the length of the line is greater than
 * sizeof(buf). But this is unlikely to happen.
 */
char *
fgetln(FILE *stream, size_t *len)
{
	static char buf[2048];
	char *p;
	const size_t bufsiz = sizeof buf;

	p = fgets(buf, bufsiz, stream);
	if (p)
		*len = strlen(p);

	return p;
}
