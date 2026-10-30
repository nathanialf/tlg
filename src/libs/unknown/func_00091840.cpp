/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

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
