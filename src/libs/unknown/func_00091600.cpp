/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: a string map's first iterator (StringMap, tlg_hk_reflect.h):
 * the index of the first used slot, or one past the hash mask when the map
 * is empty; the walks from 0x17d7b8 start with it. The index is kept at the
 * iterator's own width and compared as the slot number the iterator test
 * (FUN_00013890) reads. */
StringMap::Iterator StringMap::FUN_00091600() const /* derived name */
{
    hkUlong i = hkUlong(-1);
    while (static_cast<int>(++i) <= hashMod && entries[i].hash == hkUlong(-1)) {}
    return reinterpret_cast<Iterator>(i);
}
