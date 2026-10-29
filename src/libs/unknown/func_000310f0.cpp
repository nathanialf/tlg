/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpWorldObject380::FUN_000310f0(int count, hknpWorldObject380Record **recordsOut)
{
    int numBytes = count * sizeof(hknpWorldObject380Record);
    hknpWorldObject380Record *block = static_cast<hknpWorldObject380Record *>(
        hkContainerHeapAllocator::get().FUN_00008d70(numBytes));
    for (int i = 0; i < count; i++) {
        recordsOut[i] = block + i;
    }
}
