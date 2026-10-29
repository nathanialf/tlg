/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: c = _mm_add_ss(b, one) (docs/NOTES.md, Round 50): the base
// holds a bare vaddss whose upper lanes come from b, used as a vector; 3.3's
// _mm_add_ss is a lane insert and has no scalar-math pattern, so the compile
// adds and then inserts (vaddss; vinsertps), which reorders the rest.
void hkMatrix3::FUN_0000bd30(const hkQuaternion &quaternion) /* derived name */
{
    const Vec4 q = quaternion.vec;
    const Vec4 q2 = _mm_add_ps(q, q);
    const Vec4 t0 = _mm_mul_ps(_mm_shuffle_ps(q, q, _MM_SHUFFLE(3, 3, 3, 2)),
                               _mm_shuffle_ps(q2, q2, _MM_SHUFFLE(0, 1, 2, 2)));
    const Vec4 t1 = _mm_mul_ps(_mm_shuffle_ps(q, q, _MM_SHUFFLE(1, 0, 0, 1)),
                               _mm_shuffle_ps(q2, q2, _MM_SHUFFLE(2, 2, 1, 1)));
    const Vec4 mask0 =
        _mm_castsi128_ps(_mm_setr_epi32(0, int(0x80000000), int(0x80000000), int(0x80000000)));
    const Vec4 mask1 =
        _mm_castsi128_ps(_mm_setr_epi32(int(0x80000000), 0, int(0x80000000), int(0x80000000)));
    const Vec4 a = _mm_xor_ps(t1, mask0);
    const Vec4 b = _mm_xor_ps(t0, mask1);
    const Vec4 one = D_14b2060[29];
    const Vec4 c = _mm_add_ss(b, one);
    col0 = _mm_sub_ps(c, a);
    const Vec4 xx2 = _mm_mul_ss(q, q2);
    const Vec4 f = _mm_sub_ps(_mm_xor_ps(c, mask0), _mm_move_ss(a, xx2));
    col1 = _mm_shuffle_ps(f, f, _MM_SHUFFLE(2, 3, 0, 1));
    const Vec4 g = _mm_movehl_ps(col0, f);
    const Vec4 h = _mm_move_ss(one, _mm_sub_ss(_mm_sub_ss(one, xx2), t1));
    col2 = _mm_shuffle_ps(g, h, _MM_SHUFFLE(2, 0, 3, 1));
}
