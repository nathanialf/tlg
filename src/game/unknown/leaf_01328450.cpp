/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <immintrin.h>

#include "tlg_types.h"

/* derived names: its pointer at 0x16c5520 is in the table of function pointers
 * at 0x16c5500 (leaf_01328770.cpp's): converts the four 16.16 fixed-point
 * values its second argument points to, each the high half times 65536 plus
 * the low half in double, times the matching one of the four doubles at +0x28
 * of its third argument, to four floats at its first. The record's type is not
 * traced. */
struct Scale01328450 { /* derived name */
    u8 unknown0[0x28];
    double unknown28[4];
};

// NONMATCHING: the mask of the low halves is `vpand` with a constant in the base;
// the intrinsic `and` with 0xffff lowers to `vpxor; vpblendw` here (4.0.0, and the
// prebuilt 3.8.1 and 3.9.1 alike); a scalar loop is not vectorized (the stores may alias).
void FUN_01328450(float *destination, const u32 *source,
                  const Scale01328450 *scale) /* derived name */
{
    __m128i value = _mm_loadu_si128((const __m128i *)source);
    __m128i low = _mm_and_si128(value, _mm_set1_epi32(0xffff));
    __m128i high = _mm_srli_epi32(value, 16);
    __m256d fixed = _mm256_add_pd(_mm256_mul_pd(_mm256_cvtepi32_pd(high), _mm256_set1_pd(65536.0)),
                                  _mm256_cvtepi32_pd(low));
    _mm_storeu_ps(destination,
                  _mm256_cvtpd_ps(_mm256_mul_pd(fixed, _mm256_loadu_pd(scale->unknown28))));
}
