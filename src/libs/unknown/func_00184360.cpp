/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: equal but for its vtable, 0x16a6570, which no row names yet
// (docs/NOTES.md, Round 32).
hkVtableClassRegistry::~hkVtableClassRegistry()
{
    map.FUN_00013db0(hkContainerHeapAllocator::get());
    FUN_0000e5c0(&map);
}
