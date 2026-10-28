/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpMassChangerModifier::FUN_00069450(const void *threadContext, const void *sharedData,
                                           const hknpCdBody &bodyA, const hknpCdBody &bodyB,
                                           hknpManifold *manifold)
{
    const hknpMaterial *materialA = bodyA.material;
    const hknpMaterial *materialB = bodyB.material;
    const hknpMaterial *heavy =
        materialB->massChangerCategory == hknpMaterial::MASS_CHANGER_DEBRIS ? materialA : materialB;
    const float factor = heavy->massChangerHeavyObjectFactor.getReal();
    const float x = (factor - 1.0f) / (factor + 1.0f);
    const Vec4 moreMass = _mm_set1_ps(x + 1.0f);
    const Vec4 lessMass = _mm_set1_ps(1.0f - x);
    if (materialA->massChangerCategory == hknpMaterial::MASS_CHANGER_DEBRIS) {
        manifold->massScaleA = moreMass;
        manifold->massScaleB = lessMass;
    } else if (materialB->massChangerCategory == hknpMaterial::MASS_CHANGER_DEBRIS) {
        manifold->massScaleA = lessMass;
        manifold->massScaleB = moreMass;
    }
}
