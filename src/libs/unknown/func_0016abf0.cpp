/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpScaledConvexShapeBase::FUN_0016abf0(int faceIndex, Vec4 *planeOut,
                                             hknpFaceAngle *angleOut) const
{
    coreShape->unknownVirtual14(faceIndex, planeOut, angleOut);
    const Vec4 plane = *planeOut;
    const Vec4 distance = broadcast<3>(plane);
    if (reinterpret_cast<const u32 *>(&scale)[3] & 0xc0ffffff) {
        *planeOut = _mm_blend_ps(plane, _mm_mul_ps(distance, broadcast<0>(scale)), 8);
        *planeOut = _mm_blend_ps(
            *planeOut, _mm_sub_ps(broadcast<3>(*planeOut), _mm_dp_ps(*planeOut, translation, 0x7F)),
            8);
        return;
    }

    const Vec4 r = _mm_rcp_ps(scale);
    const Vec4 invScale = _mm_mul_ps(r, _mm_sub_ps(D_14b4380, _mm_mul_ps(scale, r)));
    const Vec4 normal = _mm_mul_ps(plane, invScale);
    const Vec4 lengthSquared = _mm_dp_ps(normal, normal, 0x7F);
    const Vec4 e = _mm_rsqrt_ps(lengthSquared);
    const Vec4 invLength =
        _mm_mul_ps(_mm_mul_ps(e, D_14b4360),
                   _mm_sub_ps(D_14b4390, _mm_mul_ps(lengthSquared, _mm_mul_ps(e, e))));
    *planeOut = _mm_mul_ps(_mm_blend_ps(normal, distance, 8), invLength);
    *planeOut = _mm_blend_ps(
        *planeOut, _mm_sub_ps(broadcast<3>(*planeOut), _mm_dp_ps(*planeOut, translation, 0x7F)), 8);

    const float angle = float(angleOut->value) * (HK_REAL_PI * 0.5f / 255.0f);
    const __m128i bits = _mm_castps_si128(normalized3(scale));
    const Vec4 direction = _mm_castsi128_ps(_mm_srli_epi32(_mm_add_epi32(bits, bits), 1));
    const Vec4 smallest = _mm_min_ps(broadcast<2>(direction),
                                     _mm_min_ps(broadcast<1>(direction), broadcast<0>(direction)));
    angleOut->value = u8(hkMath::clamp(
        int(angle * _mm_cvtss_f32(smallest) * (255.0f / (HK_REAL_PI * 0.5f)) + 0.5f), 0, 255));
}
