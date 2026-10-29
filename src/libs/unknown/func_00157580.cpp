/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpMotion::FUN_00157580(const Vec4 &position, Vec4 &velocityOut) const
{
    const Vec4 worldAngularVelocity = rotatedDir(orientation, angularVelocity);
    const Vec4 offset = _mm_sub_ps(position, centerOfMass);
    velocityOut = _mm_add_ps(cross3(worldAngularVelocity, offset), linearVelocity);
}
