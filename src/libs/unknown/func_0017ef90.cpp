/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The builtin classes registered by name with the default registry, their
 * type infos with the type info registry, and each type's vtable with the
 * vtable registry. */
hkReferencedObject *FUN_0017ef90()
{
    hkBuiltinTypeRegistry *registry = HK_NULL;
    if (D_57c8910 && D_57c8960 && D_57c8938) {
        registry = new hkBuiltinTypeRegistry;
        D_57c8960->FUN_0017ee60(D_57c8870);
        hkTypeInfoRegistry *typeInfos = D_57c8938;
        for (const hkTypeInfo *const *info = D_16c82b0; *info; info++) {
            typeInfos->FUN_0017d8b0(*info);
        }
        D_57c8910->FUN_00184540(D_16c82b0, D_16c9060);
    }
    return registry;
}
