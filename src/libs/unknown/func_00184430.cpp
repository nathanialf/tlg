/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkVtableClassRegistry::FUN_00184430(hkArray<const hkClass *> &classesOut) const
{
    for (PointerMap::Iterator it = map.getIterator(); map.isValid(it); it = map.getNext(it)) {
        classesOut.pushBack(reinterpret_cast<const hkClass *>(map.getValue(it)));
    }
}
