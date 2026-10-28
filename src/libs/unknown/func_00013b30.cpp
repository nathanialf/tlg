/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the value of a key, probed for as the key search does, or
 * the default when the key is absent. */
hkUlong PointerMap::FUN_00013b30(hkUlong key, hkUlong defaultValue) const /* derived name */
{
    if (hashMod > 0) {
        for (u32 i = u32(key >> 4) * 0x9e3779b1 & hashMod; entries[i].key != hkUlong(-1);
             i = (i + 1) & hashMod) {
            if (entries[i].key == key) {
                return entries[i].value;
            }
        }
    }
    return defaultValue;
}
