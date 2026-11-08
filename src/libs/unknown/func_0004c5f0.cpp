/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpWorld::FUN_0004c5f0(u32 bodyId, int motionId) /* derived name */
{
    hknpWorldObject4f8::MotionRecord &record = object4f8->motionRecords[motionId];
    record.byteA = static_cast<u8>(bodyId & 3);
    if (record.byteB != 0xff) {
        record.byteB = 0;
    }

    hknpMotion &motion = motionManager.motions[motionId];
    if (motion.solverId == 0x7fffffff) {
        motionManager.FUN_00047720(motion, motionId);
    }

    bodyManager.FUN_00161490(bodyId);

    recordConstraintPairs(bodyId);
}
