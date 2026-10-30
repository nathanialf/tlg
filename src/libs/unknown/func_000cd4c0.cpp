/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The cell of a position by the splitter's kind: one cell, the nearest
 * point, or the grid's (inline in the world's motion update). derived
 * name. */
static inline int cellOf(const hknpSpaceSplitter *splitter, const Vec4 &position)
{
    int cell = 0;
    switch (splitter->type) {
    case 0:
        cell = 0;
        break;
    case 1:
        static_cast<const FlaggedPoints00060c70 *>(splitter)->FUN_00061060(position, &cell);
        break;
    case 2:
        static_cast<const hknpGridSpaceSplitter *>(splitter)->FUN_00060c10(position, &cell);
        break;
    }
    return cell;
}

void hknpWorld::FUN_000cd4c0(hknpMotion &motion, u32 motionId)
{
    const int cell = cellOf(spaceSplitter, motion.centerOfMass);
    if (cell != motion.cellIndex) {
        motionManager.setCellIndex(motion, motionId, u8(cell));
    }
}
