/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The result is stored through the vector's member in each branch: the two
 * stores' addresses are two element addresses of the reference, one per
 * branch, which InstCombine's merge of the stores at the join
 * (SimplifyStoreAtEndOfBlock) does not take for one location. */
void FUN_00156cd0(const Vec4 &from, const Vec4 &to, float speed, const Vec4 &velocity,
                  hkVector4 &out) /* derived name */
{
    const Vec4 difference = _mm_sub_ps(to, from);
    const Vec4 distance = length3(difference);
    if (_mm_ucomigt_ss(distance, D_14b2060[35])) {
        const Vec4 speed4 = _mm_set1_ps(speed);
        const Vec4 scale =
            _mm_xor_ps(_mm_mul_ps(_mm_mul_ps(distance, _mm_rcp_ps(speed4)), D_14b2060[18]),
                       _mm_set1_ps(-0.0f));
        Vec4 correction = _mm_mul_ps(scale, velocity);
        const Vec4 correctionLength = length3(correction);
        if (_mm_ucomigt_ss(correctionLength, speed4)) {
            correction = _mm_mul_ps(correction, _mm_mul_ps(speed4, _mm_rcp_ps(correctionLength)));
        }
        out.quad = _mm_add_ps(correction,
                              _mm_mul_ps(difference, _mm_mul_ps(speed4, _mm_rcp_ps(distance))));
    } else {
        out.quad = difference;
    }
}
