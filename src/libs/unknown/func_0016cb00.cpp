/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

int hknpScaledConvexShapeBase::FUN_0016cb00(const Vec4 &direction, const Vec4 &point,
                                            void *argument3, bool argument4, int argument5,
                                            Vec4 *planeOut, hknpFaceAngle *angleOut) const
{
    const Vec4 r = _mm_rcp_ps(scale);
    const Vec4 invScale = _mm_mul_ps(r, _mm_sub_ps(_mm_load_ps(D_14b4380), _mm_mul_ps(scale, r)));
    const Vec4 localPoint = _mm_mul_ps(invScale, _mm_sub_ps(point, translation));

    const Vec4 d = direction;

    /* The scale's w holds the uniform scale flag as an int24. */
    hkVector4 localDirection;
    if (reinterpret_cast<const u32 *>(&scale)[3] & 0xc0ffffff) {
        localDirection.quad = _mm_mul_ps(invScale, d);
    } else {
        const Vec4 r2 = _mm_rcp_ps(invScale);
        const Vec4 s = _mm_mul_ps(r2, _mm_sub_ps(_mm_load_ps(D_14b4380), _mm_mul_ps(invScale, r2)));
        const Vec4 normal = _mm_mul_ps(d, s);
        const Vec4 lengthSquared = _mm_dp_ps(normal, normal, 0x7F);
        const Vec4 e = _mm_rsqrt_ps(lengthSquared);
        const Vec4 invLength = _mm_mul_ps(
            _mm_mul_ps(e, _mm_load_ps(D_14b4360)),
            _mm_sub_ps(_mm_load_ps(D_14b4390), _mm_mul_ps(lengthSquared, _mm_mul_ps(e, e))));
        localDirection.quad = _mm_mul_ps(_mm_blend_ps(normal, broadcast<3>(d), 8), invLength);
    }

    hkVector4 plane = localDirection;
    const int result = coreShape->unknownVirtual16(localDirection.quad, localPoint, argument3,
                                                   argument4, argument5, &plane.quad, angleOut);
    Vec4 &localPlane = plane.quad;

    if (reinterpret_cast<const u32 *>(&scale)[3] & 0xc0ffffff) {
        localPlane =
            _mm_blend_ps(localPlane, _mm_mul_ps(broadcast<3>(localPlane), broadcast<0>(scale)), 8);
        *planeOut = _mm_blend_ps(
            localPlane,
            _mm_sub_ps(broadcast<3>(localPlane), _mm_dp_ps(localPlane, translation, 0x7F)), 8);
        return result;
    }

    angleOut->value = 0;
    const Vec4 r3 = _mm_rcp_ps(scale);
    const Vec4 inverse = _mm_mul_ps(r3, _mm_sub_ps(_mm_load_ps(D_14b4380), _mm_mul_ps(scale, r3)));
    const Vec4 normal = _mm_mul_ps(localPlane, inverse);
    const Vec4 lengthSquared = _mm_dp_ps(normal, normal, 0x7F);
    const Vec4 e = _mm_rsqrt_ps(lengthSquared);
    const Vec4 invLength =
        _mm_mul_ps(_mm_mul_ps(e, _mm_load_ps(D_14b4360)),
                   _mm_sub_ps(_mm_load_ps(D_14b4390), _mm_mul_ps(lengthSquared, _mm_mul_ps(e, e))));
    localPlane = _mm_mul_ps(_mm_blend_ps(normal, broadcast<3>(localPlane), 8), invLength);
    *planeOut = _mm_blend_ps(
        localPlane, _mm_sub_ps(broadcast<3>(localPlane), _mm_dp_ps(localPlane, translation, 0x7F)),
        8);
    return result;
}
