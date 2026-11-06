/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A key's hash: h * 31 + c over its characters, the top bit cleared. Its
 * own function, inlined into the lookup already rotated, so the character
 * is a phi of the loop ahead of the hash and the sum takes the product
 * first, as the base holds it (cookbook 127's ranks). derived name. */
static inline hkUlong hashKey(const char *key)
{
    hkUlong hash = 0;
    for (const char *p = key; *p; p++) {
        hash = 31 * hash + *p;
    }
    return hash & (hkUlong(-1) >> 1);
}

/* derived name: a key's slot: the slots probed in turn from the hash's own
 * until a free one, each whose hash agrees compared by string. */
StringMap::Iterator StringMap::FUN_00091840(const char *key) const
{
    const hkUlong hash = hashKey(key);
    for (hkUlong i = hash & hashMod; entries[i].hash != hkUlong(-1); i = (i + 1) & hashMod) {
        if (entries[i].hash == hash && FUN_00017f40(key, entries[i].key) == 0) {
            return reinterpret_cast<Iterator>(i);
        }
    }
    return reinterpret_cast<Iterator>(static_cast<hkUlong>(hashMod + 1));
}

/* derived name: a key's value, or the default when the key is not in the
 * map: the lookup above inline, its slot tested against the hash mask. */
hkUlong StringMap::FUN_00091900(const char *key, hkUlong defaultValue) const
{
    const int index = int(reinterpret_cast<hkUlong>(FUN_00091840(key)));
    return index <= hashMod ? entries[index].value : defaultValue;
}

/* derived name: a key's value when its slot is in the map, through the
 * slot's lookup above (inlined). */
hkResult StringMap::FUN_000919e0(const char *key, hkUlong *valueOut) const
{
    const int slot = int(reinterpret_cast<hkUlong>(FUN_00091840(key)));
    if (slot <= hashMod) {
        *valueOut = entries[slot].value;
        return HK_SUCCESS;
    }
    return HK_FAILURE;
}

/* derived name: a key's value set: the table doubled first when it is half
 * full (every used entry inserted again into the new slots, the old ones
 * given back), then the slots probed from the hash's own; a new key takes
 * the first free one and is counted. */
void StringMap::FUN_00091690(const char *key, hkUlong value)
{
    const hkUlong hash = hashKey(key);
    if (numEntries + numEntries > hashMod) {
        Entry *oldEntries = entries;
        const int oldCapacity = hashMod + 1;
        const int newCapacity = hashMod + hashMod + 2;
        entries = static_cast<Entry *>(
            hkContainerHeapAllocator::get().blockAlloc(newCapacity * int(sizeof(Entry))));
        FUN_00018160(entries, 0xff, newCapacity * sizeof(Entry));
        numEntries = 0;
        hashMod = newCapacity - 1;
        for (int i = 0; i < oldCapacity; i++) {
            if (oldEntries[i].hash != hkUlong(-1)) {
                FUN_00091690(oldEntries[i].key, oldEntries[i].value);
            }
        }
        hkContainerHeapAllocator::get().blockFree(oldEntries, oldCapacity * int(sizeof(Entry)));
    }
    hkUlong i = hash & hashMod;
    for (;;) {
        if (entries[i].hash == hkUlong(-1)) {
            numEntries++;
            break;
        }
        if (entries[i].hash == hash && FUN_00017f40(key, entries[i].key) == 0) {
            break;
        }
        i = (i + 1) & hashMod;
    }
    entries[i].hash = hash;
    entries[i].key = key;
    entries[i].value = value;
}
