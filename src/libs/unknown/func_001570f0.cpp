/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

void FUN_001570f0(ShapeMass001570f0 &out, const hknpShape *shape)
{
    hkDiagonalizedMassProperties properties;
    const hknpShapeMassProperties *shapeMass =
        shape->properties
            ? static_cast<const hknpShapeMassProperties *>(shape->properties->FUN_0001c550(0xf100))
            : HK_NULL;
    if (shapeMass) {
        shapeMass->compressedMassProperties.FUN_000263e0(properties);
    } else {
        MassConfig00168340 config;
        shape->unknownVirtual28(&config, &properties);
    }
    out.centerOfMassAndVolume =
        _mm_blend_ps(properties.centerOfMass, _mm_set1_ps(properties.volume), 8);
    out.inertiaOverMass = _mm_mul_ps(_mm_set1_ps(1.0f / properties.mass), properties.inertiaTensor);
    out.majorAxisSpace = properties.majorAxisSpace.vec;
}
