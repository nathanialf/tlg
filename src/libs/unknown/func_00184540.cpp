/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: every type info with a vtable registers it under the
 * class at the same place in the class list (slot 5), until either list
 * ends. */
void hkVtableClassRegistry::FUN_00184540(const hkTypeInfo *const *infos,
                                         const hkClass *const *classes)
{
    const hkTypeInfo *const *ti = infos;
    const hkClass *const *ci = classes;
    while (*ti && *ci) {
        if (const void *vtable = (*ti)->vtable) {
            FUN_00184520(vtable, *ci);
        }
        ++ti;
        ++ci;
    }
}
