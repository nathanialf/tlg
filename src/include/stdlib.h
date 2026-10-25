/* The C library's <stdlib.h>, as much of it as the executable's imports
 * attest, declared by us (docs/FINISHING.md rule 8: Sony's and the C
 * library's API through headers of our own, never Sony's). The build finds
 * it in place of the host's because -nostdlibinc hides the host's headers;
 * the compiler's own xmmintrin.h includes it (through mm_malloc.h) in a
 * hosted build, and the build is hosted because the original was: memcpy,
 * memmove and memset are lowered as builtins throughout the executable
 * (docs/DECISIONS.md D11). */
#ifndef TLG_STDLIB_H
#define TLG_STDLIB_H

typedef unsigned long size_t;

extern "C" {
void *malloc(size_t size);
void free(void *p);
int posix_memalign(void **memptr, size_t alignment, size_t size);
}

#endif
