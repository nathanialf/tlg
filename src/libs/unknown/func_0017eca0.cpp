/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkDynamicClassNameRegistry::FUN_0017eca0(hkArray<const hkClass *> &classesOut) const
{
    for (StringMap::Iterator it = map.FUN_00091600(); map.FUN_00013890(it);
         it = map.FUN_00091650(it)) {
        classesOut.expandOne() = reinterpret_cast<const hkClass *>(map.FUN_00091640(it));
    }
}
