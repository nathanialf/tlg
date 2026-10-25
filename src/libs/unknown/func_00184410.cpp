/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hkVtableClassRegistry's vtable (address point
 * 0x16a6580) returns the class registered for a vtable, or null. */
const hkClass *hkVtableClassRegistry::FUN_00184410(const void *vtable) const /* derived name */
{
    return reinterpret_cast<const hkClass *>(
        map.FUN_00013b30(reinterpret_cast<hkUlong>(vtable), 0));
}
