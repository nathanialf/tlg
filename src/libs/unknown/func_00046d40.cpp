/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hknpMotionManager::MotionIterator::MotionIterator(const hknpMotionManager &motionManager)
    : manager(&motionManager), index(0)
{
    next();
}
