/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 7 of hkVtableClassRegistry's vtable (address point
 * 0x16a6580) returns the class registered for a polymorphic object's
 * vtable (its first word), or null; slot 6 (FUN_00184410) takes the vtable
 * itself. */
const hkClass *hkVtableClassRegistry::FUN_00184420(const void *object) const /* derived name */
{
    const void *vtable = *static_cast<const void *const *>(object);
    return reinterpret_cast<const hkClass *>(
        map.FUN_00013b30(reinterpret_cast<hkUlong>(vtable), 0));
}
