/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A vector scaled to unit length over x, y and z, zero where its squared
 * length is not positive, its length returned, as Havok's
 * hkVector4::normalizeWithLength<3> is on this platform: one reciprocal
 * square root refined by a Newton step gives both. derived name. */
static inline Vec4 normalizeWithLength3(Vec4 &v) /* derived name */
{
    const Vec4 lengthSquared = _mm_dp_ps(v, v, 0x7F);
    const Vec4 e = _mm_rsqrt_ps(lengthSquared);
    const Vec4 invLength =
        _mm_andnot_ps(_mm_cmple_ps(lengthSquared, _mm_setzero_ps()),
                      _mm_mul_ps(_mm_mul_ps(e, _mm_load_ps(D_14b4360)),
                                 _mm_sub_ps(_mm_load_ps(D_14b4390),
                                            _mm_mul_ps(lengthSquared, _mm_mul_ps(e, e)))));
    v = _mm_mul_ps(v, invLength);
    return _mm_mul_ps(lengthSquared, invLength);
}

/* Whether x, y and z are all zero. derived name. */
static inline bool allEqualZero3(const Vec4 &v) /* derived name */
{
    const __m128 xyz = _mm_blend_ps(_mm_setzero_ps(), _mm_castsi128_ps(_mm_set1_epi32(-1)), 7);
    return _mm_testc_si128(_mm_castps_si128(_mm_and_ps(_mm_cmpeq_ps(v, _mm_setzero_ps()), xyz)),
                           _mm_castps_si128(xyz));
}

void hknpCharacterProxy::FUN_00177e00(const hkArray<int> &supports,
                                      hknpCharacterSurfaceInfo &surface,
                                      const hkStepInfo &stepInfo) /* derived name */
{
    D_16dc078->timerBegin("TtgetGround");
    surface.surfaceDistanceExcess = 0.0f;
    surface.surfaceIsDynamic = false;
    surface.surfaceVelocity = _mm_setzero_ps();
    surface.surfaceNormal = _mm_setzero_ps();
    const int numSupports = supports.getSize();
    for (int i = 0; i < numSupports; i++) {
        const hknpCharacterProxyContact &contact = contacts[supports[i]];
        surface.surfaceNormal =
            _mm_add_ps(surface.surfaceNormal, contact.contactPoint.separatingNormal);
        surface.surfaceDistanceExcess += contact.contactPoint.getDistance();
        const hknpBody &body = world->bodyManager.bodies[contact.bodyId.value];
        if (body.flags & hknpBody::IS_STATIC) {
            continue;
        }
        const hknpMotion &motion = world->motionManager.motions[body.motionId];
        /* The body's velocity at the contact: the rotation it turns
         * through in a step applied to the contact's offset, over the
         * step, plus the linear velocity. */
        Vec4 axis;
        motion.FUN_00157510(axis);
        Vec4 angularPart = _mm_setzero_ps();
        if (!allEqualZero3(axis)) {
            hkQuaternion rotation;
            rotation.FUN_00019cf0(
                axis, _mm_mul_ps(normalizeWithLength3(axis), _mm_set1_ps(stepInfo.deltaTime)));
            const Vec4 offset = _mm_sub_ps(contact.contactPoint.position, motion.centerOfMass);
            Vec4 rotated;
            FUN_00011060(rotated, rotation, offset);
            angularPart =
                _mm_mul_ps(_mm_sub_ps(rotated, offset), _mm_set1_ps(stepInfo.invDeltaTime));
        }
        const Vec4 velocity = _mm_mul_ps(_mm_add_ps(angularPart, motion.linearVelocity),
                                         _mm_set1_ps(contact.velocityWeight));
        surface.surfaceVelocity = _mm_add_ps(surface.surfaceVelocity, velocity);
        if (body.flags & hknpBody::IS_DYNAMIC) {
            surface.surfaceIsDynamic = true;
        }
    }
    surface.surfaceNormal = normalized3(surface.surfaceNormal);
    const Vec4 count = broadcast<0>(_mm_cvtsi32_ss(_mm_setzero_ps(), numSupports));
    const Vec4 r = _mm_rcp_ps(count);
    const Vec4 invCount = _mm_mul_ps(r, _mm_sub_ps(_mm_load_ps(D_14b4380), _mm_mul_ps(count, r)));
    surface.surfaceVelocity = _mm_mul_ps(surface.surfaceVelocity, invCount);
    surface.surfaceDistanceExcess = surface.surfaceDistanceExcess * _mm_cvtss_f32(invCount);
    if ((world->bodyManager.bodies[bodyId.value].flags & 8) && surface.surfaceIsDynamic) {
        surface.surfaceDistanceExcess = 0.01f;
    } else {
        surface.surfaceDistanceExcess = surface.surfaceDistanceExcess - keepDistance;
    }
    D_16dc078->timerEnd("Et");
}
