/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: a string map's next iterator (StringMap, tlg_hk_reflect.h):
 * the index of the next used slot after the iterator's, or one past the
 * hash mask at the end. */
StringMap::Iterator StringMap::FUN_00091650(Iterator it) const /* derived name */
{
    int i = static_cast<int>(reinterpret_cast<hkUlong>(it));
    for (i += 1; i <= hashMod; ++i) {
        if (entries[i].hash != hkUlong(-1)) {
            break;
        }
    }
    return reinterpret_cast<Iterator>(static_cast<hkUlong>(i));
}
