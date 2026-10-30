/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void BroadPhaseLayers00142a40::FUN_00143390(const u32 *ids, int numIds, int striding)
{
    for (int i = 0; i < numIds; i++) {
        const u32 id = *ids;
        if (id >= u32(markedBodies.storage.numBits)) {
            markedBodies.FUN_00047b30(0, (id + 32) & ~31, 0);
        }
        markedBodies.set(id);
        lowestMarkedId = hkMath::min2(lowestMarkedId, id);
        highestMarkedId = hkMath::max2(highestMarkedId, id);
        ids = hkAddByteOffsetConst(ids, striding);
    }
}
