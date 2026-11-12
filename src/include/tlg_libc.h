/* The C library functions the executable imports, declared here because the
 * host's libc headers are hidden (-nostdlibinc; docs/FINISHING.md rule 8).
 * Each name is the import's verified NID name (tools/nid_names.py), reached
 * through its PLT stub. The build is hosted, so memcpy, memmove and memset
 * are the compiler's builtins, lowered as the base shows (D11). */
#ifndef TLG_LIBC_H
#define TLG_LIBC_H

#include <stdarg.h>

#include "stdlib.h"

typedef long time_t;
/* FreeBSD's clock_t, a 32-bit int (the seed at 0xdb5f keeps eax). */
typedef int clock_t;
/* The C library's stream, opaque here (FreeBSD's struct __sFILE). */
typedef struct __sFILE FILE;
/* fseek's origins: the start and the end of the stream (FreeBSD's stdio.h). */
#define SEEK_SET 0
#define SEEK_END 2
/* Positive infinity as a float, as the C library's math.h spells it. */
#define HUGE_VALF __builtin_huge_valf()

/* A file's status as stat fills it: FreeBSD 9's amd64 layout, 0x78 bytes
 * (FUN_00e5c830's buffer), the mode a 16-bit word at +0x8. */
struct timespec {
    time_t tv_sec;
    long tv_nsec;
};

struct stat {
    unsigned int st_dev;
    unsigned int st_ino;
    unsigned short st_mode;
    unsigned short st_nlink;
    unsigned int st_uid;
    unsigned int st_gid;
    unsigned int st_rdev;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    long st_size;
    long st_blocks;
    unsigned int st_blksize;
    unsigned int st_flags;
    unsigned int st_gen;
    int st_lspare;
    struct timespec st_birthtim;
};

/* The mode's directory and regular-file bits (FreeBSD's sys/stat.h). */
#define S_IFDIR 0040000
#define S_IFREG 0100000

extern "C" {
int strcmp(const char *a, const char *b);
int strncmp(const char *a, const char *b, size_t n);
int memcmp(const void *a, const void *b, size_t n);
void *memcpy(void *dst, const void *src, size_t n);
void *memmove(void *dst, const void *src, size_t n);
void *memset(void *dst, int c, size_t n);
char *strcpy(char *dst, const char *src);
char *strncpy(char *dst, const char *src, size_t n);
char *strcat(char *dst, const char *src);
size_t strlen(const char *s);
char *strchr(const char *s, int c);
char *strstr(const char *s, const char *find);
time_t time(time_t *t);
clock_t clock(void);
int printf(const char *format, ...);
int sprintf(char *s, const char *format, ...);
int vsnprintf(char *s, size_t n, const char *format, va_list args);
void perror(const char *message);
int puts(const char *s);
void srand(unsigned int seed);
size_t fread(void *ptr, size_t size, size_t n, FILE *stream);
size_t fwrite(const void *ptr, size_t size, size_t n, FILE *stream);
int fseek(FILE *stream, long offset, int whence);
long ftell(FILE *stream);
int fflush(FILE *stream);
FILE *fopen(const char *path, const char *mode);
int fclose(FILE *stream);
/* NID verified as "stat" (E6ao34wPw+U). */
int stat(const char *path, struct stat *status);
float fabsf(float x);
/* NIDs verified as "acosf", "asinf", "atanf", "tanf", "expf". */
float acosf(float x);
float asinf(float x);
float atanf(float x);
float tanf(float x);
float expf(float x);
/* The C library's float sine and cosine kernel (Dinkumware's; its NID
 * verified as "_FSin"): the sine for a quadrant offset of 0, the cosine for
 * 1; the third argument is 0 at every one of the executable's 1,709 calls. */
float _FSin(float x, unsigned int quadrantOffset, int unknown);

inline float sinf(float x)
{
    return _FSin(x, 0, 0);
}

inline float cosf(float x)
{
    return _FSin(x, 1, 0);
}

void *memalign(size_t alignment, size_t size);
/* The C library's string-to-unsigned-long conversion (Dinkumware's, behind
 * strtoul; its NID verified as "_Stoul"). */
unsigned long _Stoul(const char *s, char **endptr, int base);
/* Sony's C library extension: the usable size of a block from any of its
 * spaces (its NID verified as "sceLibcMspaceMallocUsableSize"). */
size_t sceLibcMspaceMallocUsableSize(void *ptr);
/* Sony's C library spaces: an allocation from one space (the NIDs verified
 * as "sceLibcMspaceMalloc", "sceLibcMspaceCalloc", "sceLibcMspaceMemalign"). */
typedef void *SceLibcMspace;
void *sceLibcMspaceMalloc(SceLibcMspace space, size_t size);
void *sceLibcMspaceCalloc(SceLibcMspace space, size_t count, size_t size);
void *sceLibcMspaceMemalign(SceLibcMspace space, size_t boundary, size_t size);
/* Dinkumware's case-mapping tables of the current locale, indexed by an
 * unsigned char (their NIDs verified as "_Getptolower" and "_Getptoupper";
 * the result is indexed directly, so the table itself, not a pointer to it). */
const short *_Getptolower(void);
const short *_Getptoupper(void);
}

#endif
