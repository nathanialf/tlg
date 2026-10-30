/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* Two materials' values combined by a policy: the smaller one, the
 * geometric mean (zero when the product is not positive) or the larger
 * one. derived name. */
static inline Vec4 combineValues(int policy, const Vec4 &a, const Vec4 &b) /* derived name */
{
    switch (policy) {
    case hknpMaterial::COMBINE_AVG: {
        const Vec4 product = _mm_mul_ps(a, b);
        return _mm_andnot_ps(_mm_cmple_ps(product, _mm_setzero_ps()),
                             _mm_mul_ps(product, _mm_rsqrt_ps(product)));
    }
    case hknpMaterial::COMBINE_MIN:
        return _mm_min_ps(a, b);
    default:
        return _mm_max_ps(a, b);
    }
}

// NONMATCHING: 53 of 81, the policies' switch and every operation the
// base's: the first loads' schedule differs (the base loads the second
// material's static friction first and keeps the friction policy in r8b),
// three bytes short (docs/NOTES.md, Round 63A).
/* The cache's friction and restitution from the two bodies' materials, each
 * by the stricter of the two policies; the static friction kept as what it
 * adds to the friction, never below zero. derived name. */
void FUN_00179ed0(hknpManifoldCollisionCache *cache, const hknpMaterial &materialA,
                  const hknpMaterial &materialB) /* derived name */
{
    const u8 frictionPolicy = materialA.frictionCombinePolicy > materialB.frictionCombinePolicy
                                  ? materialA.frictionCombinePolicy
                                  : materialB.frictionCombinePolicy;
    const Vec4 staticFriction = _mm_max_ps(_mm_set1_ps(materialA.staticFriction.getReal()),
                                           _mm_set1_ps(materialB.staticFriction.getReal()));
    const Vec4 friction =
        combineValues(frictionPolicy, _mm_set1_ps(materialA.dynamicFriction.getReal()),
                      _mm_set1_ps(materialB.dynamicFriction.getReal()));
    const u8 restitutionPolicy =
        materialA.restitutionCombinePolicy > materialB.restitutionCombinePolicy
            ? materialA.restitutionCombinePolicy
            : materialB.restitutionCombinePolicy;
    const Vec4 staticFrictionExtra = _mm_max_ps(_mm_sub_ps(staticFriction, friction), D_14b2060[2]);
    const Vec4 restitution =
        combineValues(restitutionPolicy, _mm_set1_ps(materialA.restitution.getReal()),
                      _mm_set1_ps(materialB.restitution.getReal()));
    cache->restitution.setReal(restitution);
    cache->friction.setReal(friction);
    cache->staticFrictionExtra.setReal(staticFrictionExtra);
}
