/* src/libs/havok/Physics/Physics/Dynamics/Motion/hknpMotionManager.cpp:
 * the file its report names (config/homes.base.txt, FUN_000475c0). */
#include "tlg_lib_unknown.h"

u32 hknpMotionManager::FUN_000475c0()
{
    if (firstFreeMotionId == 0x7fffffff) {
        HK_ERROR(0x606609a5, HK_NP_MOTION_MANAGER_CPP, 286, "Motion buffer is full.");
        return 0x7fffffff;
    }
    const u32 motionId = firstFreeMotionId;
    hknpMotion &motion = motions[motionId];
    firstFreeMotionId = motion.nextFreeMotionId;
    motion.firstAttachedBodyId = 0x7fffffff;
    motion.unknown3f = 1;
    peakMotionIndex = hkMath::max2(peakMotionIndex, motionId);
    numUsedMotions++;
    return motionId;
}

hknpMotionManager::~hknpMotionManager()
{
    if (!storageIsExternal) {
        FUN_0000bc00(*D_16dc070->temp58, motions.data);
    }
}
