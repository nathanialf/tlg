/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the active bodies' ids, padded with four zeros past the end
 * so a reader of four at a time never reads garbage. */
const hkArray<u32> &hknpBodyManager::FUN_001612e0()
{
    u32 *padding = activeBodyIds.expandByUnchecked(4);
    padding[0] = 0;
    padding[1] = 0;
    padding[2] = 0;
    padding[3] = 0;
    activeBodyIds.setSizeUnchecked(activeBodyIds.getSize() - 4);
    return activeBodyIds;
}
