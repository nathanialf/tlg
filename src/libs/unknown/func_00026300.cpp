/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

void hkDiagonalizedMassProperties::FUN_00026300(const hkMassProperties &properties)
{
    centerOfMass = properties.centerOfMass;
    mass = properties.mass;
    volume = properties.volume;

    hkMatrix3 axes;
    hkMatrix3 inertia = properties.inertiaTensor;
    FUN_0002a7a0(inertia, axes);
    inertiaTensor = _mm_blend_ps(_mm_blend_ps(inertia.col0, inertia.col1, 2), inertia.col2, 4);
    inertiaTensor = _mm_blend_ps(inertiaTensor, _mm_set1_ps(properties.volume), 8);
    majorAxisSpace.FUN_0001a1c0(axes);
}
