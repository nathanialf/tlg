/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_libc.h"

/* derived names: the string library's character search, a wrapper over the
 * imported strchr; its one direct caller (0x17f58a) looks for '.' in a
 * member path. */
char *FUN_00018060(const char *s, int c) /* derived name */
{
    return strchr(s, c);
}
