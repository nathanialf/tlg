/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: the loop is the base's; the preheader shares the full bit's
// `and` between the shift and the mask in the base (0x156ebc), where 3.3
// here folds the mask's use into `or 0x7e; inc` on the byte and redoes the
// `and` for the shift (docs/NOTES.md, Round 55).
/* derived name: slot 6 of the modifier at 0x16a4860: the cache's second
 * point array lowered to each point's distance plus the shared vector
 * scaled by the float under property key 2, and to zero. */
void Modifier16a4860::FUN_00156e90(const void *threadContext,
                                   const ModifierSharedData00156e90 *sharedData, const void *bodyA,
                                   const void *bodyB, hknpManifold *manifold) /* derived name */
{
    hknpManifoldCollisionCache *cache = manifold->collisionCache;
    float *values = cache->pointValues(1);
    const Vec4 scale = simdFromFloat(*cache->getProperty<float>(2));
    for (int i = 0; i < manifold->numPoints; i += 4) {
        Vec4 &value = *reinterpret_cast<Vec4 *>(values + i);
        const Vec4 distance = _mm_add_ps(_mm_mul_ps(scale, sharedData->object->vector),
                                         _mm_load_ps(manifold->distances + i));
        value = _mm_min_ps(_mm_min_ps(_mm_setzero_ps(), value), distance);
    }
}
