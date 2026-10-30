/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_lib_unknown.h"

/* The magnitude of each lane, as FUN_0001add0's file spells it (cookbook
 * 70). derived name. */
static inline Vec4 absLanes(const Vec4 &v) /* derived name */
{
    const __m128i bits = _mm_castps_si128(v);
    return _mm_castsi128_ps(_mm_srli_epi32(_mm_add_epi32(bits, bits), 1));
}

void FUN_00178460(Object00178580 *self, const Vec4 &angularVelocity) /* derived name */
{
    hknpWorld *world = self->world;
    const hknpMotion &motion =
        world->motionManager.motions[world->bodyManager.bodies[self->index].motionId];
    const Vec4 current = rotatedDir(motion.orientation, motion.angularVelocity);
    const __m128i all = _mm_set1_epi32(-1);
    const __m128 xyz = _mm_blend_ps(_mm_setzero_ps(), _mm_castsi128_ps(all), 7);
    const Vec4 close = _mm_cmple_ps(absLanes(_mm_sub_ps(angularVelocity, current)), D_14b2060[35]);
    if (!_mm_testc_si128(_mm_castps_si128(_mm_and_ps(close, xyz)), _mm_castps_si128(xyz))) {
        const Vec4 linearVelocity = motion.linearVelocity;
        FUN_0005dc50(world, self->index, linearVelocity, angularVelocity);
    }
}
