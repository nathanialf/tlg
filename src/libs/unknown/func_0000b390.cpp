/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The removal through the map's own member, the insertion through the
 * owned map's inline one: the two branches begin differently (the base
 * conversion first in one, the key's extension in the other), so each
 * keeps its own extension of the key (SimplifyCFG hoists only leading
 * identical instructions). */
void Object0000b330::FUN_0000b390(int id, bool enabled)
{
    criticalSection.enter();
    if (enabled) {
        map.FUN_00013d10(hkUlong(id));
    } else {
        map.insert(hkUlong(id), 1);
    }
    criticalSection.leave();
}
