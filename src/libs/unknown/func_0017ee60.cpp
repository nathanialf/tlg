/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkDynamicClassNameRegistry::FUN_0017ee60(const hkClassNameRegistry &other)
{
    hkArray<const hkClass *> classes;
    other.FUN_0017eca0(classes);
    for (int i = 0; i < classes.size; i++) {
        FUN_0017ed70(classes[i], 0);
    }
}
