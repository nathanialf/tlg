/* The C library functions the executable imports, declared here because the
 * host's libc headers are hidden (-nostdlibinc; docs/FINISHING.md rule 8).
 * Each name is the import's verified NID name (tools/nid_names.py), reached
 * through its PLT stub. The build is hosted, so memcpy, memmove and memset
 * are the compiler's builtins, lowered as the base shows (D11). */
#ifndef TLG_LIBC_H
#define TLG_LIBC_H

#include "stdlib.h"

typedef long time_t;

extern "C" {
int strcmp(const char *a, const char *b);
int strncmp(const char *a, const char *b, size_t n);
int memcmp(const void *a, const void *b, size_t n);
void *memcpy(void *dst, const void *src, size_t n);
void *memmove(void *dst, const void *src, size_t n);
void *memset(void *dst, int c, size_t n);
char *strcpy(char *dst, const char *src);
char *strncpy(char *dst, const char *src, size_t n);
size_t strlen(const char *s);
char *strchr(const char *s, int c);
time_t time(time_t *t);
/* The C library's string-to-unsigned-long conversion (Dinkumware's, behind
 * strtoul; its NID verified as "_Stoul"). */
unsigned long _Stoul(const char *s, char **endptr, int base);
}

#endif
