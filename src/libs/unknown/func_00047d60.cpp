/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 2 of the world's material slot: the signal asks
 * whether a slot holds a given member function before it unsubscribes it,
 * the held one read first (cookbook 55: its loads sink past the size test
 * and are not folded). */
int hknpWorldMaterialSlot::FUN_00047d60(const void *otherMethod, int size) const
{
    Method held = method;
    if (size == sizeof(Method)) {
        return *static_cast<const Method *>(otherMethod) == held;
    }
    return 0;
}
