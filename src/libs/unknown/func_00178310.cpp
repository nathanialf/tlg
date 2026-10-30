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

void FUN_00178310(Object00178580 *self, const Vec4 &linearVelocity, const Vec4 &deltaTime,
                  bool activate) /* derived name */
{
    hknpWorld *world = self->world;
    const hknpMotion &motion =
        world->motionManager.motions[world->bodyManager.bodies[self->index].motionId];
    const Vec4 change = _mm_sub_ps(linearVelocity, motion.linearVelocity);
    const __m128i all = _mm_set1_epi32(-1);
    const __m128 xyz = _mm_blend_ps(_mm_setzero_ps(), _mm_castsi128_ps(all), 7);
    const Vec4 close = _mm_cmple_ps(absLanes(change), D_14b2060[35]);
    if (_mm_testc_si128(_mm_castps_si128(_mm_and_ps(close, xyz)), _mm_castps_si128(xyz))) {
        if (activate) {
            world->FUN_0004e0c0(self->index);
        }
        return;
    }
    const Vec4 t = deltaTime;
    const Vec4 r = _mm_rcp_ps(t);
    self->acceleration = _mm_mul_ps(change, _mm_mul_ps(r, _mm_sub_ps(D_14b4380, _mm_mul_ps(t, r))));
    const Vec4 angularVelocity = rotatedDir(motion.orientation, motion.angularVelocity);
    FUN_0005dc50(world, self->index, linearVelocity, angularVelocity);
}
