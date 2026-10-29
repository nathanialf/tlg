/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: 33 of 34: the second row times the translation's y takes
// its operands the other way round (`vmulps xmm2, xmm2, xmm4` for the base's
// `vmulps xmm2, xmm4, xmm2`): Reassociate sorts a commutative product by
// rank (3.3 Reassociate.cpp, OptimizeInst), and the second row's two
// shuffles rank one above the broadcast of y where the other rows tie with
// theirs (docs/NOTES.md, Round 52).
void hknpShapeInstance::FUN_0003ead0(hkTransform &inverseOut) const
{
    const Vec4 r = _mm_rcp_ps(scale);
    const Vec4 inverseScale = _mm_mul_ps(r, _mm_sub_ps(D_14b4380, _mm_mul_ps(scale, r)));
    const Vec4 c0 = transform.rotation.col0;
    const Vec4 c1 = transform.rotation.col1;
    const Vec4 c2 = transform.rotation.col2;
    const Vec4 lo = _mm_unpacklo_ps(c0, c1);
    const Vec4 col0 = _mm_mul_ps(inverseScale, _mm_movelh_ps(lo, c2));
    inverseOut.rotation.col0 = col0;
    const Vec4 col1 = _mm_mul_ps(
        inverseScale, _mm_shuffle_ps(_mm_movehl_ps(lo, lo), c2, _MM_SHUFFLE(3, 1, 1, 0)));
    inverseOut.rotation.col1 = col1;
    const Vec4 col2 = _mm_mul_ps(
        inverseScale, _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, _MM_SHUFFLE(3, 2, 1, 0)));
    inverseOut.rotation.col2 = col2;
    const Vec4 t = transform.translation;
    const Vec4 x = _mm_shuffle_ps(t, t, _MM_SHUFFLE(0, 0, 0, 0));
    const Vec4 y = _mm_shuffle_ps(t, t, _MM_SHUFFLE(1, 1, 1, 1));
    const Vec4 z = _mm_shuffle_ps(t, t, _MM_SHUFFLE(2, 2, 2, 2));
    const Vec4 rotated =
        _mm_add_ps(_mm_mul_ps(col2, z), _mm_add_ps(_mm_mul_ps(col0, x), _mm_mul_ps(col1, y)));
    inverseOut.translation = _mm_xor_ps(
        rotated,
        _mm_castsi128_ps(_mm_setr_epi32(int(0x80000000), int(0x80000000), int(0x80000000), 0)));
}
