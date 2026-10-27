/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkDynamicClassNameRegistry::FUN_0017edb0(const hkClass *const *classes)
{
    for (const hkClass *const *klass = classes; *klass; ++klass) {
        FUN_0017ed70(*klass, 0);
    }
}
