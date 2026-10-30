/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkDiagonalizedMassProperties::FUN_00026490(hkMassProperties &out) const
{
    hkMatrix3 rotation;
    rotation.FUN_0000bd30(majorAxisSpace);
    hkMatrix3 scaled;
    scaled.col0 = _mm_mul_ps(broadcast<0>(inertiaTensor), rotation.col0);
    scaled.col1 = _mm_mul_ps(broadcast<1>(inertiaTensor), rotation.col1);
    scaled.col2 = _mm_mul_ps(broadcast<2>(inertiaTensor), rotation.col2);
    out.inertiaTensor.FUN_0001abb0(scaled, rotation);
    out.volume = volume;
    out.centerOfMass = centerOfMass;
    out.mass = mass;
}
