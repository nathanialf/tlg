/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_libc.h"

/* derived names: the string library's bounded copy, a wrapper over the
 * imported strncpy that copies nothing for a zero count; the count is an
 * unsigned 32-bit int, widened by zero extension. hkStringPtr's setter
 * (0xe521) terminates the copy itself. */
void FUN_00017fd0(char *dst, const char *src, unsigned int n) /* derived name */
{
    if (n != 0) {
        strncpy(dst, src, n);
    }
}
