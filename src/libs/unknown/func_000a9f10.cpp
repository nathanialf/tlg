/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: a box inside a parent box from its four bytes of code:
 * each byte's high nibble moves the minimum in and its low nibble the
 * maximum, by the square of the nibble in 255ths of the parent's
 * extent. */
void FUN_000a9f10(const hkAabb &parent, const u8 *codes, hkAabb &aabbOut) /* derived name */
{
    const __m128i bytes = _mm_castps_si128(_mm_load_ss(reinterpret_cast<const float *>(codes)));
    const Vec4 extent = _mm_mul_ps(_mm_sub_ps(parent.max, parent.min), D_14b2060[27]);
    const __m128i zero = _mm_setzero_si128();
    const __m128i values = _mm_unpacklo_epi16(_mm_unpacklo_epi8(bytes, zero), zero);
    const Vec4 high = _mm_cvtepi32_ps(_mm_srli_epi32(values, 4));
    const Vec4 low = _mm_cvtepi32_ps(_mm_and_si128(values, _mm_castps_si128(D_57c87c0)));
    aabbOut.min = _mm_add_ps(parent.min, _mm_mul_ps(extent, _mm_mul_ps(high, high)));
    aabbOut.max = _mm_sub_ps(parent.max, _mm_mul_ps(extent, _mm_mul_ps(low, low)));
}
