/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpWorldObject380::FUN_00031170(hknpWorldObject380Record **records, int count)
{
    hkContainerHeapAllocator::get().FUN_00008d80(records[0],
                                                 count * sizeof(hknpWorldObject380Record));
    for (int i = 0; i < count; i++) {
        records[i] = 0;
    }
}
