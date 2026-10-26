/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the value of the string map entry an iterator stands at
 * (StringMap, tlg_hk_reflect.h); the walks from 0x17d7e0 read the key and
 * value of each entry with this and its neighbour. */
hkUlong StringMap::FUN_00091640(Iterator it) const /* derived name */
{
    int slot = static_cast<int>(reinterpret_cast<hkUlong>(it));
    return entries[slot].value;
}
