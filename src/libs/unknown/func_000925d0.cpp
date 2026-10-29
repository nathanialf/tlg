/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void *RefArrays::FUN_000925d0(RefArraysAllocator *allocator, EntryId entryId)
{
    Entry10 &entry = array10.data[entryId.value];
    entry.unknownE = 1;
    entry.unknownC = u16(array30.size);
    void *&pointer = array30.expandOne();
    allocator->allocate(&pointer, 1);
    return pointer;
}
