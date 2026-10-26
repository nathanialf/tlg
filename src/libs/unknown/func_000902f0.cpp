/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the class of the variant's object, from its vtable through
 * the vtable class registry, or null without an object. */
const hkClass *FUN_000902f0(const hkRefVariant *self)
{
    if (self->object) {
        return D_57c8910->FUN_00184420(self->object);
    }
    return 0;
}
