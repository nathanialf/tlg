/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_libc.h"

/* derived names: the string library's copy, a wrapper over the imported
 * strcpy whose callers ignore the result (0xe42e copies into a block just
 * allocated). */
void FUN_00017fc0(char *dst, const char *src) /* derived name */
{
    strcpy(dst, src);
}
