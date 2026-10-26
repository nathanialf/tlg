/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: a string map emptied (StringMap, tlg_hk_reflect.h): every
 * slot's hash the free -1, the count zero; the storage is kept. */
void StringMap::FUN_00091ac0()
{
    for (int i = 0; i <= hashMod; i++) {
        entries[i].hash = hkUlong(-1);
    }
    numEntries = 0;
}
