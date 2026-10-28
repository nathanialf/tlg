/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkDynamicClassNameRegistry::FUN_0017edf0(const StringMap &classes)
{
    for (StringMap::Iterator it = classes.FUN_00091600(); classes.FUN_00013890(it);
         it = classes.FUN_00091650(it)) {
        FUN_0017ed70(reinterpret_cast<const hkClass *>(classes.FUN_00091640(it)), 0);
    }
}
