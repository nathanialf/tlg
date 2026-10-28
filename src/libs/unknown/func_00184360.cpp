/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkVtableClassRegistry::~hkVtableClassRegistry()
{
    map.FUN_00013db0(hkContainerHeapAllocator::get());
    FUN_0000e5c0(&map);
}
