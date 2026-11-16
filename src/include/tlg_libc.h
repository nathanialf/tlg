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
/* NID verified as "rand"; its largest value is 0x3fffffff (the modulus and
 * the reciprocal 2^-30 of FUN_00dc0020) */
int rand(void);
#define RAND_MAX 0x3fffffff
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
/* Not an import: under the game's -ffast-math the compiler lowers it to the
 * reciprocal square root estimate and its Newton step (FUN_00f51880). */
float sqrtf(float x);
/* NIDs verified as "acosf", "asinf", "atanf", "tanf", "expf". */
float acosf(float x);
float asinf(float x);
float atanf(float x);
float tanf(float x);
float expf(float x);
/* NIDs verified as "atan2f", "fmodf", "powf", "tanhf" (FUN_00de6ee0,
 * FUN_00de7490, FUN_00de77a0, FUN_00de7c90). */
float atan2f(float y, float x);
float fmodf(float x, float y);
float powf(float x, float y);
float tanhf(float x);
/* Imports too, but under the game's -ffast-math the compiler lowers them to
 * the SSE4.1 round (`vroundss` modes 2 and 1, FUN_00de7030 and FUN_00de73b0). */
float ceilf(float x);
float floorf(float x);
/* NIDs verified as "frexpf", "ldexpf", "modff" (FUN_00dbf760, FUN_00dbf870,
 * FUN_00dbfe30). */
float frexpf(float x, int *exponent);
float ldexpf(float x, int exponent);
float modff(float x, float *whole);
/* Dinkumware's kernels behind the hyperbolic functions and the logarithms
 * (their NIDs verified as "_FCosh", "_FSinh" and "_FLog"): the hyperbolic
 * functions times y, the logarithm in base e for 0 and base 10 for 1. */
float _FCosh(float x, float y);
float _FSinh(float x, float y);
float _FLog(float x, int base);

inline float coshf(float x)
{
    return _FCosh(x, 1.0f);
}

inline float sinhf(float x)
{
    return _FSinh(x, 1.0f);
}

inline float logf(float x)
{
    return _FLog(x, 0);
}

inline float log10f(float x)
{
    return _FLog(x, 1);
}

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

/* The C++ library's float overloads of sin and cos (Dinkumware's <cmath>
 * calls the kernel from them directly). The compiler knows sinf and cosf as
 * pure library functions and drops a call whose result is unused; these
 * overloads are ordinary functions to it, and the calls stay (0x344450,
 * 0x3447b0). */
inline float sin(float x)
{
    return _FSin(x, 0, 0);
}

inline float cos(float x)
{
    return _FSin(x, 1, 0);
}

#endif
