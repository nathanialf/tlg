/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 5 of hknpLinearSurfaceVelocity's vtable (address point 0x16a4bc0). */
void hknpLinearSurfaceVelocity::calcVelocities(const hkVector4 &, const hkVector4 &normal,
                                               const hknpBody &body,
                                               hkVector4 *HK_RESTRICT linearVelocityOut,
                                               hkVector4 *HK_RESTRICT angularVelocityOut) const
{
    angularVelocityOut->quad = _mm_setzero_ps();
    Vec4 linear;
    if (space == USE_LOCAL_SPACE) {
        const hkMatrix3 &rotation = body.transform.rotation;
        linear = combineColumns(rotation.col0, rotation.col1, rotation.col2, velocity.quad);
    } else {
        linear = velocity.quad;
    }
    if (projectMethod != VELOCITY_PROJECT) {
        const Vec4 n = normal.quad;
        const Vec4 projected = _mm_sub_ps(linear, _mm_mul_ps(n, _mm_dp_ps(n, linear, 0x7F)));
        const Vec4 plane = velocityMeasurePlane.quad;
        const Vec4 measured =
            _mm_sub_ps(projected, _mm_mul_ps(plane, _mm_dp_ps(plane, projected, 0x7F)));
        const Vec4 length = length3(linear);
        const Vec4 maxScale = _mm_set1_ps(maxVelocityScale);
        const Vec4 scale = _mm_min_ps(
            _mm_max_ps(lengthInverse3(measured), _mm_sub_ps(_mm_setzero_ps(), maxScale)), maxScale);
        linear = _mm_mul_ps(projected, _mm_mul_ps(length, scale));
    }
    linearVelocityOut->quad = linear;
}
