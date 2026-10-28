/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpMotionManager::FUN_000476a0(int motionId) /* derived name */
{
    hknpMotion &motion = motions[motionId];
    motion.reset();
    motion.nextFreeMotionId = firstFreeMotionId;
    firstFreeMotionId = motionId;
    numUsedMotions--;
}
