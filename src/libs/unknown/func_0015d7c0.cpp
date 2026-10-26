/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <xmmintrin.h>

#include "tlg_hk_reflect.h"

/* derived name: slot 3 of the modifier at 0x16a4de0: a new manifold's cache
 * gets a 16-byte vector under property key 1, zeroed. */
void Modifier16a4de0::FUN_0015d7c0(const void *threadContext, const void *sharedData,
                                   const void *bodyA, const void *bodyB,
                                   ManifoldCreatedInput *input) /* derived name */
{
    Vec4 *property = static_cast<Vec4 *>(FUN_0017a0a0(input->collisionCache, 1, 16, 16));
    *property = _mm_setzero_ps();
}
