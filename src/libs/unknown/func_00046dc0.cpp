/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 328 bytes against 589: the base holds the cells' setSize
// inline (the lost lists freed from the last, the new ones cleared,
// 0x46e3c to 0x46f44), which the debug opt (a78/llvm33dbg) prices 325
// against its hinted threshold of 325 here, one InstrCost over: the fourth
// witness of exactly that margin (0x277e0, 0xacfc0, 0x167420; NOTES "Round
// 78A").
void hknpMotionManager::FUN_00046dc0(hknpMotion *userMotionBuffer, int capacity,
                                     hknpBodyManager *newBodyManager,
                                     const hknpSpaceSplitter *splitter)
{
    bodyManager = newBodyManager;
    FUN_00047010(userMotionBuffer, capacity);

    /* The static motion: cleared, the identity, no cell, then in use. */
    hknpMotion &staticMotion = motions[0];
    hkString::memSet16(&staticMotion, &D_14b2060[2], sizeof(staticMotion) / 16);
    staticMotion.orientation.vec = D_14b2060[32];
    staticMotion.cellIndex = 0xff;
    staticMotion.motionPropertiesId = 0;
    motions[0].unknown3f = 1;

    const int numCells = splitter->numCells;
    activeMotionsPerCell.setSize(numCells);
    if (numCells > 0) {
        const int perCell = 4 * capacity / numCells;
        for (int i = 0; i < numCells; i++) {
            activeMotionsPerCell[i].reserve(hkContainerHeapAllocator::get(), perCell);
            activeMotionsPerCell[i].pushBack(0);
        }
    }
    firstFreeMotionId = 1;
    numUsedMotions = 1;
    peakMotionIndex = 0;
}
