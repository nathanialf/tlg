/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"
#include "tlg_libc.h"

/* derived name: a memory move with a signed int count. A destination above
 * the source is copied backwards by FUN_00091100; one below it goes to the
 * imported memmove; the same address needs nothing. */
void FUN_00091210(void *dst, const void *src, int n)
{
    if (dst > src) {
        FUN_00091100(dst, src, n);
    } else if (dst < src) {
        memmove(dst, src, n);
    }
}
