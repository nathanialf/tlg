/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpMotionManager::FUN_00047790(hknpMotion &motion, u32 motionId) /* derived name */
{
    hkArray<u32> &cell = activeMotionsPerCell[motion.cellIndex];
    const int last = cell.getSize() - 1;
    const u32 index = motion.solverId;
    if (index < u32(last)) {
        const u32 movedId = cell[last];
        motions[movedId].solverId = index;
        cell[index] = movedId;
    }
    motion.solverId = 0x7fffffff;
    cell.setSizeUnchecked(cell.getSize() - 1);
}
