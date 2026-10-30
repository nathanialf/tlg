/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the key's hash (its address bits above the low four times
 * Knuth's golden-ratio constant) picks the first slot; the probe steps to
 * the next until the key or an empty slot. */
PointerMap::Iterator PointerMap::FUN_00013ad0(hkUlong key) const /* derived name */
{
    if (hashMod > 0) {
        for (u32 i = u32(key >> 4) * 0x9e3779b1 & hashMod; entries[i].key != hkUlong(-1);
             i = (i + 1) & hashMod) {
            if (entries[i].key == key) {
                return reinterpret_cast<Iterator>(hkUlong(i));
            }
        }
    }
    return reinterpret_cast<Iterator>(long(hashMod + 1));
}

hkResult PointerMap::FUN_00013d10(hkUlong key) /* derived name */
{
    Iterator it = FUN_00013ad0(key);
    if (!isValid(it)) {
        return HK_FAILURE;
    }
    FUN_00013c10(it);
    return HK_SUCCESS;
}

hkResult PointerMap::FUN_00013b90(hkUlong key, hkUlong &out) const /* derived name */
{
    Iterator it = FUN_00013ad0(key);
    if (!isValid(it)) {
        return HK_FAILURE;
    }
    out = getValue(it);
    return HK_SUCCESS;
}

/* A key in use (the map operations' test, inline: its argument a named
 * value, so the key is loaded before the compare). derived name. */
static inline bool isValidKey(hkUlong key) /* derived name */
{
    return key != hkUlong(-1);
}

/* derived name: the entry emptied, then the run it sat in closed up: each
 * later entry of the run whose home slot is not between the run's start
 * and its own slot moves into the hole, which moves to it. */
void PointerMap::FUN_00013c10(Iterator it) /* derived name */
{
    u32 i = u32(reinterpret_cast<hkUlong>(it));
    numEntries -= 1;
    entries[i].key = hkUlong(-1);

    u32 lo = (i + hashMod) & hashMod;
    while (isValidKey(entries[lo].key)) {
        lo = (lo + hashMod) & hashMod;
    }
    lo = (lo + 1) & hashMod;

    u32 empty = i;
    for (i = (i + 1) & hashMod; isValidKey(entries[i].key); i = (i + 1) & hashMod) {
        const u32 hash = u32(entries[i].key >> 4) * 0x9e3779b1 & hashMod;
        if (i >= lo && hash > empty) {
            continue;
        } else if (i < empty && (hash > empty || hash <= i)) {
            continue;
        } else if (hash > empty && hash < lo) {
            continue;
        }
        entries[empty].key = entries[i].key;
        entries[empty].value = entries[i].value;
        entries[i].key = hkUlong(-1);
        empty = i;
    }
}
