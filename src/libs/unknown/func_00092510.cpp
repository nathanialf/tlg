/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void RefArrays::FUN_00092510(int numEntries, int numInts)
{
    array10.reserve(hkContainerHeapAllocator::get(), numEntries);
    array20.reserve(hkContainerHeapAllocator::get(), numInts);
    references.reserve(hkContainerHeapAllocator::get(), numEntries);
}
