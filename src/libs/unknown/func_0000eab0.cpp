/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: an hkStringPtr setter that forwards its string and length
 * unchanged to FUN_0000e450. Six direct callers, among them 0x19e3ac with a
 * stack string and a computed length. */
void FUN_0000eab0(hkStringPtr *self, const char *string, int length) /* derived name */
{
    FUN_0000e450(self, string, length);
}
