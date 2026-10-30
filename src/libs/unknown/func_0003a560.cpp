/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hknpBodyCinfo::hknpBodyCinfo() : shape(HK_NULL)
{
    materialId = 0;
    flags = 0;
    collisionFilterInfo = 0;
    shape = HK_NULL;
    qualityId = 0xff;
    userData = 0;
    motionType = 0;
    position = _mm_setzero_ps();
    orientation = D_14b2060[32];
    angularVelocity = _mm_setzero_ps();
    linearVelocity = _mm_setzero_ps();
    mass = -1.0f;
    massDistribution = HK_NULL;
    motionPropertiesId = 0xffff;
    reservedBodyId = 0x7fffffff;
    reservedMotionId = 0x7fffffff;
    collisionLookAheadDistance = 0.0f;
    localFrame = HK_NULL;
}
