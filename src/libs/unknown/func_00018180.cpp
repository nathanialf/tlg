/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_libc.h"

/* derived names: the string library's memory compare, a wrapper over the
 * imported memcmp beside the copy and fill wrappers FUN_00018150 and
 * FUN_00018160; the count is an unsigned 32-bit int, widened by zero
 * extension. Six callers (0x4c23c compares 8 bytes against zeros). */
int FUN_00018180(const void *a, const void *b, unsigned int n) /* derived name */
{
    return memcmp(a, b, n);
}
