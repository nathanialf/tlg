/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void Modifier16a4860::FUN_00156dc0(const void *threadContext, const void *sharedData,
                                   const hknpCdBody *bodyA, const hknpCdBody *bodyB,
                                   ManifoldCreatedInput *input) /* derived name */
{
    const hknpMaterial *materialA = bodyA->material;
    const hknpMaterial *materialB = bodyB->material;
    const hknpMaterial *material = u32(materialA->softContactForceFactor.value - 1) <
                                           u32(materialB->softContactForceFactor.value - 1)
                                       ? materialA
                                       : materialB;
    const float forceFactor = material->softContactForceFactor.getReal();
    const float dampFactor = material->softContactDampFactor.getReal();
    ManifoldScaleProperty *property =
        static_cast<ManifoldScaleProperty *>(FUN_0017a0a0(input->collisionCache, 2, 16, 16));
    const Vec4 damp = simdFromFloat(dampFactor);
    const Vec4 r = _mm_rcp_ps(damp);
    const Vec4 inverseDamp = _mm_mul_ps(r, _mm_sub_ps(D_14b4380, _mm_mul_ps(damp, r)));
    const Vec4 ratio = _mm_mul_ps(simdFromFloat(forceFactor), inverseDamp);
    property->separationVelocity = material->softContactSeperationVelocity.getReal();
    property->scaleB = _mm_cvtss_f32(_mm_min_ps(ratio, D_14b2060[3]));
    property->scaleA = dampFactor;
}
