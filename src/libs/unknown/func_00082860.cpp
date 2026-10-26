/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 22 of hkpConstraintData's vtable (0x169fb80), kept by
 * the derived constraint data vtables (0x1695bd0, 0x1699b50, ...): clears
 * the runtime of a new constraint instance, if it has one. */
void hkpConstraintData::FUN_00082860(void *runtime, int sizeOfRuntime) const /* derived name */
{
    if (runtime) {
        FUN_00018160(runtime, 0, sizeOfRuntime);
    }
}
