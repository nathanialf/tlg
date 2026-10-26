/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the string map's destructor, out of line: its entries go
 * back to the containers' allocator. */
void FUN_000915e0(StringMap *self)
{
    hkContainerHeapAllocator::get().blockFree(self->entries,
                                              sizeof(StringMap::Entry) * (self->hashMod + 1));
}
