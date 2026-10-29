/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkBuiltinTypeRegistry::FUN_0017ef10(const hkTypeInfo *info, const hkClass *klass)
{
    D_57c8960->FUN_0017ed70(klass, klass->FUN_00004200());
    D_57c8938->FUN_0017d8b0(info);
    if (klass->FUN_000042b0() > 0) {
        D_57c8910->FUN_00184520(info->vtable, klass);
    }
}
