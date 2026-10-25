/* The C library functions the executable imports, declared here because the
 * build is freestanding (-nostdinc). Each name is the import's verified NID
 * name (tools/nid_names.py), reached through its PLT stub. */
#ifndef TLG_LIBC_H
#define TLG_LIBC_H

typedef unsigned long size_t;

extern "C" {
int strcmp(const char *a, const char *b);
int strncmp(const char *a, const char *b, size_t n);
int memcmp(const void *a, const void *b, size_t n);
char *strcpy(char *dst, const char *src);
size_t strlen(const char *s);
char *strchr(const char *s, int c);
}

#endif
