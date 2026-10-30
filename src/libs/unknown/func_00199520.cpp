/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the value of a key, probed for as the pointer map does, or
 * the default when the key is absent. */
template <typename V> V U16PointerMap::FUN_00199520(u16 key, V defaultValue) const
{
    if (hashMod > 0) {
        for (u32 i = u32(key >> 4) * 0x9e3779b1 & hashMod; entries[i].key != u16(-1);
             i = (i + 1) & hashMod) {
            if (entries[i].key == key) {
                return reinterpret_cast<V>(entries[i].value);
            }
        }
    }
    return defaultValue;
}

/* The bit field map's instantiation (0x1659c0 and the world's lookups at
 * 0x176ebc and 0x177394). */
template BitFieldMap00199770::Block *
U16PointerMap::FUN_00199520(u16 key, BitFieldMap00199770::Block *defaultValue) const;
