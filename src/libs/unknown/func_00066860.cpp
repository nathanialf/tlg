/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

namespace
{

/* Each lane truncated to an integer, a lane at or above 2^31 given every
 * bit but the sign (the conversion's 0x80000000 flipped), as Havok's
 * float-to-integer conversion is on this platform. derived name. */
inline __m128i convertToInt32(const Vec4 &v) /* derived name */
{
    const Vec4 tooLarge = _mm_cmple_ps(_mm_set1_ps(2147483648.0f), v);
    return _mm_xor_si128(_mm_cvttps_epi32(v), _mm_castps_si128(tooLarge));
}

} // namespace

void hknpWorldObject4f8::MotionRecord::FUN_00066860(int value, bool flag)
{
    const Vec4 vector = _mm_mul_ps(_mm_mul_ps(D_14b2060[3], _mm_set1_ps(1024.0f)), D_14b2060[2]);
    const __m128i fields = _mm_and_si128(convertToInt32(vector), _mm_set1_epi32(1023));

    const Vec4 c = _mm_set1_ps(1.1f);
    const Vec4 r = _mm_rcp_ps(c);
    const Vec4 inverse = _mm_mul_ps(r, _mm_sub_ps(D_14b4380, _mm_mul_ps(r, c)));
    const Vec4 rotation = _mm_mul_ps(_mm_mul_ps(inverse, _mm_set1_ps(128.0f)), D_14b2060[32]);

    byteA = static_cast<u8>(value & 3);
    byteB = flag ? 0 : 0xff;
    const __m128i packed =
        _mm_or_si128(_mm_or_si128(fields, _mm_shuffle_epi32(_mm_slli_epi32(fields, 10), 0x39)),
                     _mm_shuffle_epi32(_mm_slli_epi32(fields, 20), 0x4e));
    _mm_store_ss(reinterpret_cast<float *>(&packedVector), _mm_castsi128_ps(packed));
    __m128i bytes = _mm_add_epi32(convertToInt32(rotation), _mm_set1_epi32(127));
    bytes = _mm_packs_epi32(bytes, bytes);
    bytes = _mm_packus_epi16(bytes, bytes);
    _mm_store_ss(reinterpret_cast<float *>(packedRotation), _mm_castsi128_ps(bytes));
}
