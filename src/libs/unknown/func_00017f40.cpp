/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_libc.h"

/* derived names: the string library's compare, a wrapper over the imported
 * strcmp, first of a run of such wrappers (0x17f50 over strncmp, 0x17fc0
 * over strcpy, 0x17fe0 over strlen, 0x18060 over strchr). 27 direct
 * callers, among them the class lookup by name FUN_0017de40. */
int FUN_00017f40(const char *a, const char *b) /* derived name */
{
    return strcmp(a, b);
}
