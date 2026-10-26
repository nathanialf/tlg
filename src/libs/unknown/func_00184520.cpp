/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 5 of hkVtableClassRegistry's vtable (address point
 * 0x16a6580) registers the class of a vtable. */
void hkVtableClassRegistry::FUN_00184520(const void *vtable,
                                         const hkClass *klass) /* derived name */
{
    map.FUN_000138a0(D_57b8480, reinterpret_cast<hkUlong>(vtable),
                     reinterpret_cast<hkUlong>(klass));
}
