/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_libc.h"

/* derived names: the string library's bounded compare, a wrapper over the
 * imported strncmp beside FUN_00017f40's strcmp; the count is an unsigned
 * 32-bit int, widened by zero extension. Two callers (0x19d877, 0x19dcea). */
int FUN_00017f50(const char *a, const char *b, unsigned int n) /* derived name */
{
    return strncmp(a, b, n);
}
