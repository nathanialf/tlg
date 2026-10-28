/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hknpMotionManager::hknpMotionManager()
    : firstFreeMotionId(0x7fffffff), numUsedMotions(0), peakMotionIndex(0)
{
}
