/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: whether two classes are the same, by address or by name;
 * never the same as no class. */
bool FUN_00004210(const hkClass *self, const hkClass *other) /* derived name */
{
    if (other == 0) {
        return false;
    }
    if (self == other) {
        return true;
    }
    return FUN_00017f40(self->name, other->name) == 0;
}
