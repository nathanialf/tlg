/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpWorld::FUN_0005f530(int motionId, const Vec4 &inertia) /* derived name */
{
    const Vec4 inverseInertia = reciprocalOrZero(inertia);
    hknpMotion &motion = motionManager.motions[motionId];
    const Vec4 packed = loadHalves(motion.inverseInertia);
    storeHalves(motion.inverseInertia, _mm_blend_ps(inverseInertia, packed, 8));
}
