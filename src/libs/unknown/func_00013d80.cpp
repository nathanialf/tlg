/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the map emptied: every slot's key the empty -1, the count
 * zero with the storage flag kept. */
// NONMATCHING: the loop guard. The base tests the mask's sign (`test; js`, then `inc` for the
// count), the fold of `hashMod + 1 > 0` that needs the add's nsw; under -fwrapv the add has
// none and the guard stays `inc; test; jle`. docs/NOTES.md Round 28.
void UlongMap::FUN_00013d80()
{
    int capacity = hashMod + 1;
    for (int i = 0; i < capacity; i++) {
        elems[i].key = hkUlong(-1);
    }
    numElems &= DONT_DEALLOCATE_FLAG;
}
