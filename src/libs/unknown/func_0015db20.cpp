/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <xmmintrin.h>

#include "tlg_hk_reflect.h"

/* derived name: slot 3 of the modifier at 0x16a4e60, called when a manifold
 * is created: its cache takes the smaller of the two materials' contact
 * impulse limits, as a half, and the smaller of their fractions of a
 * clipped impulse to apply, in 255ths. */
void Modifier16a4e60::FUN_0015db20(const void *threadContext, const void *sharedData,
                                   const hknpCdBody *bodyA, const hknpCdBody *bodyB,
                                   ManifoldCreatedInput *input) /* derived name */
{
    const hknpMaterial *materialA = bodyA->material;
    const hknpMaterial *materialB = bodyB->material;
    const float fraction = hkMath::min2(materialA->fractionOfClippedImpulseToApply,
                                        materialB->fractionOfClippedImpulseToApply);
    hknpManifoldCollisionCache *cache = input->collisionCache;
    cache->maxImpulse.setReal(_mm_min_ps(_mm_load1_ps(&materialA->maxContactImpulse),
                                         _mm_load1_ps(&materialB->maxContactImpulse)));
    cache->fractionOfClippedImpulseToApply = u8(fraction * 255.0f);
}
