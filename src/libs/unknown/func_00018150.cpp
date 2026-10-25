/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_libc.h"

/* derived names: the string library's overlapping memory copy, a wrapper over
 * the imported memmove beside FUN_00017e70 (memcpy) and FUN_00018180
 * (memcmp); the count is an unsigned 32-bit int, widened by zero extension.
 * Three callers (0x47251, 0x15feb1, 0x16d63a). */
void FUN_00018150(void *dst, const void *src, unsigned int n) /* derived name */
{
    memmove(dst, src, n);
}
