/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the table rebuilt at twice its size plus two when more than
 * half full, then the key probed for as the key search does; a new key takes
 * the empty slot the probe stops at and is counted. */
int PointerMap::FUN_000138a0(AllocatorBase &allocator, hkUlong key,
                             hkUlong value) /* derived name */
{
    if (2 * numEntries > hashMod) {
        FUN_00013940(allocator, hashMod + hashMod + 2);
    }
    int isNew = 1;
    u32 i;
    for (i = u32(key >> 4) * 0x9e3779b1 & hashMod; entries[i].key != hkUlong(-1);
         i = (i + 1) & hashMod) {
        if (entries[i].key == key) {
            isNew = 0;
            break;
        }
    }
    numEntries += isNew;
    entries[i].key = key;
    entries[i].value = value;
    return isNew;
}
