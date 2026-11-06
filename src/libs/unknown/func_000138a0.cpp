/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the table rebuilt at twice its size plus two when more than
 * half full, then the key probed for as the key search does; a new key takes
 * the empty slot the probe stops at and is counted. */
template <typename V>
int PointerMap::FUN_000138a0(AllocatorBase &allocator, hkUlong key, V value) /* derived name */
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
    entries[i].value = hkUlong(value);
    return isNew;
}

/* derived name: at least eight slots from the allocator, all empty, then
 * every used entry of the old table inserted again (the insert inline);
 * the old table given back unless the map did not own it, a failure when
 * the allocator gives nothing. */
hkResult PointerMap::FUN_00013940(AllocatorBase &allocator, int newCapacity) /* derived name */
{
    newCapacity = hkMath::max2(newCapacity, 8);
    const int oldNumEntries = numEntries;
    Pair *oldEntries = entries;
    const int oldCapacity = hashMod + 1;
    Pair *newEntries = static_cast<Pair *>(allocator.blockAlloc(newCapacity * int(sizeof(Pair))));
    if (newEntries == HK_NULL) {
        return HK_FAILURE;
    }
    entries = newEntries;
    for (int i = 0; i < newCapacity; i++) {
        entries[i].key = hkUlong(-1);
    }
    numEntries = 0;
    hashMod = newCapacity - 1;
    for (int i = 0; i < oldCapacity; i++) {
        if (oldEntries[i].key != hkUlong(-1)) {
            FUN_000138a0(allocator, oldEntries[i].key, oldEntries[i].value);
        }
    }
    if ((oldNumEntries & DONT_DEALLOCATE_FLAG) == 0) {
        allocator.blockFree(oldEntries, oldCapacity * int(sizeof(Pair)));
    }
    return HK_SUCCESS;
}

/* The word's instantiation. */
template int PointerMap::FUN_000138a0(AllocatorBase &allocator, hkUlong key, hkUlong value);
