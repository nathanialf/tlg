/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hknpMotionCinfo::hknpMotionCinfo()
{
    motionPropertiesId = 0xffff;
    enableDeactivation = true;
    inverseMass = 1.0f;
    inverseInertiaLocal = D_14b2060[3];
    maxLinearAccelerationDistancePerStep = HK_REAL_HIGH;
    maxRotationPerStep = HK_REAL_HIGH;
    centerOfMassWorld = _mm_setzero_ps();
    orientation.vec = D_14b2060[32];
    angularVelocity = _mm_setzero_ps();
    linearVelocity = _mm_setzero_ps();
}
