/*
 * Public domain.
 */

#ifndef OPENBSD
#define OPENBSD

#include <sys/types.h>
#include <stdio.h>

size_t strlcpy(char *dst, const char *src, size_t size);
size_t strlcat(char *dst, const char *src, size_t size);
long long strtonum(const char *nptr, long long minval, long long maxval, const char **errstr);
char *fgetln(FILE *stream, size_t *len);

#define __dead

#endif

