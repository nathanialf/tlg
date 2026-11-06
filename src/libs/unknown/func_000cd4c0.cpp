/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpWorld::FUN_000cd4c0(hknpMotion &motion, u32 motionId)
{
    const int cell = cellOf(spaceSplitter, motion.centerOfMass);
    if (cell != motion.cellIndex) {
        motionManager.setCellIndex(motion, motionId, u8(cell));
    }
}
