/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>
#include <tmmintrin.h>

#include "tlg_hk_reflect.h"

/* The three mantissas scaled to the largest component's exponent (the w
 * lane held at 2^-46 so a zero vector has one), converted with saturation,
 * rounded, and their high halves kept beside the shared exponent. */
void hkPackedVector3::FUN_00092ef0(const Vec4 &v)
{
    const __m128 vw = _mm_blend_ps(v, D_14b2060[36], 8);
    __m128i exponent = _mm_castps_si128(_mm_and_ps(_mm_mul_ps(vw, _mm_set1_ps(1.0000152587890625f)),
                                                   _mm_castsi128_ps(_mm_set1_epi32(0x7f800000))));
    exponent = _mm_max_epi32(exponent, _mm_shuffle_epi32(exponent, 0x4e));
    exponent = _mm_max_epi32(exponent, _mm_shuffle_epi32(exponent, 0xb1));
    const __m128 scaled = _mm_castsi128_ps(
        _mm_sub_epi32(_mm_add_epi32(_mm_castps_si128(v), _mm_set1_epi32(0x4e800000)), exponent));
    const __m128 overflow = _mm_cmple_ps(_mm_set1_ps(2147483648.0f), scaled);
    const __m128i mantissas = _mm_xor_si128(_mm_cvttps_epi32(scaled), _mm_castps_si128(overflow));
    const __m128i shared = _mm_add_epi32(exponent, _mm_set1_epi32(int(0xb1800000)));
    __m128i packed =
        _mm_castps_si128(_mm_blend_ps(_mm_castsi128_ps(shared), _mm_castsi128_ps(mantissas), 7));
    packed = _mm_add_epi32(packed, _mm_set_epi32(0x3f800000, 0x8000, 0x8000, 0x8000));
    packed = _mm_shuffle_epi8(packed,
                              _mm_set_epi8(15, 14, 11, 10, 7, 6, 3, 2, 15, 14, 11, 10, 7, 6, 3, 2));
    _mm_storel_epi64(reinterpret_cast<__m128i *>(values), packed);
}
