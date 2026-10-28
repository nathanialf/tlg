/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpMotionManager::FUN_00047720(hknpMotion &motion, u32 motionId) /* derived name */
{
    hkArray<u32> &cell = activeMotionsPerCell[motion.cellIndex];
    motion.solverId = cell.getSize();
    cell.pushBack(motionId);
}
