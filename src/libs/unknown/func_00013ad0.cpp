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
