/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_libc.h"

/* derived names: the string library's length, a wrapper over the imported
 * strlen returning an int (0xe3ff uses the low 32 bits). */
int FUN_00017fe0(const char *s) /* derived name */
{
    return (int)strlen(s);
}
