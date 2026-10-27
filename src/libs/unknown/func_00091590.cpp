/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The string map's constructor (StringMap, tlg_hk_reflect.h): sixteen free
 * slots, the hash mask fifteen. */
StringMap::StringMap()
{
    entries = static_cast<Entry *>(hkContainerHeapAllocator::get().blockAlloc(16 * sizeof(Entry)));
    FUN_00018160(entries, 0xff, 16 * sizeof(Entry));
    numEntries = 0;
    hashMod = 15;
}
