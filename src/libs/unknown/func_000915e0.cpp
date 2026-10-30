/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The string map's destructor, out of line: its entries go back to the
 * containers' allocator. */
StringMap::~StringMap()
{
    hkContainerHeapAllocator::get().blockFree(entries, sizeof(Entry) * (hashMod + 1));
}
