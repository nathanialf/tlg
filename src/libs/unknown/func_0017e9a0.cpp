/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkBuiltinTypeRegistry::FUN_0017e9a0()
{
    hkDefaultClassNameRegistry *classNameRegistry = new hkDefaultClassNameRegistry();
    if (D_57c8960) {
        D_57c8960->removeReference();
    }
    D_57c8960 = classNameRegistry;

    hkTypeInfoRegistry *typeInfoRegistry = new hkTypeInfoRegistry();
    if (D_57c8938) {
        D_57c8938->removeReference();
    }
    D_57c8938 = typeInfoRegistry;

    hkVtableClassRegistry *vtableClassRegistry = new hkVtableClassRegistry();
    if (D_57c8910) {
        D_57c8910->removeReference();
    }
    D_57c8910 = vtableClassRegistry;

    D_57c8960->FUN_0017ee60(D_57c8870);
    hkTypeInfoRegistry *infos = D_57c8938;
    for (const hkTypeInfo *const *info = D_16c82b0; *info; info++) {
        infos->FUN_0017d8b0(*info);
    }
    D_57c8910->FUN_00184540(D_16c82b0, D_16c9060);
}
