/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The compressed mass properties a shape keeps under key 0xf100, null when
 * it has none. derived name. */
static inline const hknpShapeMassProperties *shapeMassOf(const hknpShape *shape)
{
    return shape->properties ? static_cast<const hknpShapeMassProperties *>(
                                   shape->properties->FUN_0001c550(0xf100))
                             : HK_NULL;
}

void FUN_00161b40(const hknpShape *shape, const ShapeMass001570f0 *summary,
                  hkDiagonalizedMassProperties &out, float mass)
{
    if (summary) {
        out.volume = lane(summary->centerOfMassAndVolume, 3);
        out.mass = 1.0f;
        out.centerOfMass = setXYZ_0(summary->centerOfMassAndVolume);
        out.inertiaTensor = setXYZ_0(summary->inertiaOverMass);
        out.majorAxisSpace.vec = summary->majorAxisSpace;
        if (mass < 0.0f) {
            const hknpShapeMassProperties *shapeMass = shapeMassOf(shape);
            mass = shapeMass ? shapeMass->compressedMassProperties.mass : 1.0f;
        }
    } else {
        const hknpShapeMassProperties *shapeMass = shapeMassOf(shape);
        if (shapeMass) {
            shapeMass->compressedMassProperties.FUN_000263e0(out);
        } else {
            MassConfig00168340 config;
            shape->unknownVirtual28(&config, &out);
        }
    }
    if (mass >= 0.0f) {
        if (mass > 0.0f) {
            out.inertiaTensor = _mm_mul_ps(_mm_set1_ps(mass / out.mass), out.inertiaTensor);
        }
        out.mass = mass;
    }
}
