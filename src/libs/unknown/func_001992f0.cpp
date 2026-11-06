/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the pointer map's insert (0x138a0) over 16-bit keys. */
template <typename V> int U16PointerMap::FUN_001992f0(AllocatorBase &allocator, u16 key, V value)
{
    if (2 * numEntries > hashMod) {
        FUN_00199390(allocator, hashMod + hashMod + 2);
    }
    int isNew = 1;
    u32 i;
    for (i = u32(key >> 4) * 0x9e3779b1 & hashMod; entries[i].key != u16(-1);
         i = (i + 1) & hashMod) {
        if (entries[i].key == key) {
            isNew = 0;
            break;
        }
    }
    numEntries += isNew;
    entries[i].key = key;
    entries[i].value = reinterpret_cast<hkUlong>(value);
    return isNew;
}

/* The bit field map's instantiation (0x1659c0). */
template int U16PointerMap::FUN_001992f0(AllocatorBase &allocator, u16 key,
                                         BitFieldMap00199770::Block *value);

/* derived name: the pointer map's rebuild (0x13940) over 16-bit keys. */
hkResult U16PointerMap::FUN_00199390(AllocatorBase &allocator, int newCapacity)
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
        entries[i].key = 0xffff;
    }
    numEntries = 0;
    hashMod = newCapacity - 1;
    for (int i = 0; i < oldCapacity; i++) {
        if (oldEntries[i].key != 0xffff) {
            FUN_001992f0(allocator, oldEntries[i].key, oldEntries[i].value);
        }
    }
    if ((oldNumEntries & DONT_DEALLOCATE_FLAG) == 0) {
        allocator.blockFree(oldEntries, oldCapacity * int(sizeof(Pair)));
    }
    return HK_SUCCESS;
}
