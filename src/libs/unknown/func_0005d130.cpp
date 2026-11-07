/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

// NONMATCHING: 506 bytes as the base, every instruction but the transform's
// columns: the base takes each column's address into its own register (`lea
// rdi/rsi/rdx/rcx, [r12 + rbx + 0..0x30]`, 0x5d1a0) and loads and stores the
// second and third columns through them, the first column loaded before the
// addresses; here every access folds the address (docs/NOTES.md, Round 75B).
void hknpWorld::FUN_0005d130(int bodyId, const Vec4 &position, int activation)
{
    hknpBody &body = bodyManager.bodies[bodyId];
    const Vec4 difference = hkMath::quadFabs(_mm_sub_ps(body.transform.translation, position));
    const __m128i all = _mm_set1_epi32(-1);
    const __m128 xyz = _mm_blend_ps(_mm_setzero_ps(), _mm_castsi128_ps(all), 7);
    if (_mm_testc_si128(_mm_castps_si128(_mm_and_ps(_mm_cmple_ps(difference, D_14b2060[35]), xyz)),
                        _mm_castps_si128(xyz))) {
        return;
    }

    hkTransform transform = body.transform;
    transform.translation = position;
    body.setTransformKeepingW(transform);
    FUN_0005c900(bodyId, HK_NULL, 0, activation);

    if (body.motionId == 0) {
        signals.staticBodyMovedSignal.fire(this, bodyId);
    }
    signals.bodyChangedSignal.fire(this, bodyId);
}
