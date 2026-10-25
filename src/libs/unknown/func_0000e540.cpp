/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: hkStringPtr's constructor from a string and its length
 * (called at 0x19e0a7). */
void FUN_0000e540(hkStringPtr *self, const char *string, int length) /* derived name */
{
    self->stringAndFlag = 0;
    FUN_0000e450(self, string, length);
}
