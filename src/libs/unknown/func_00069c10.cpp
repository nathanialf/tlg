/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_lib_unknown.h"

/* The manifolds are the modifier's own (HK_RESTRICT, docs/DECISIONS.md D9):
 * the stream's end, stored when the timer begins, is not read again after
 * the points are moved (0x69e03 compares the register). */
void hknpTriangleWeldingModifier::FUN_00069c10(const void *threadContext, const void *sharedData,
                                               const void *argument3,
                                               const hknpCdBodyForCollide &cdBodyA,
                                               const hknpCdBodyForCollide &cdBodyB,
                                               hknpManifold *HK_RESTRICT manifolds,
                                               int numManifolds)
{
    ThreadBuffer *stream = D_16dc078;
    stream->timerBegin("TtTriangleWelding");
    const Vec4 relativeVelocity =
        _mm_sub_ps(cdBodyA.motion->linearVelocity, cdBodyB.motion->linearVelocity);
    for (int i = 0; i < numManifolds; i++) {
        hknpManifold &manifold = manifolds[i];
        if (!manifold.weldingType) {
            continue;
        }
        const Vec4 normal = manifold.normal.quad;
        const Vec4 triangleNormal = manifold.unknown20.quad;
        const Vec4 cosAngle = _mm_dp_ps(normal, triangleNormal, 0x7f);
        if (_mm_cvtss_f32(cosAngle) >= 0.99f) {
            continue;
        }
        const Vec4 minusTolerance = _mm_sub_ps(_mm_setzero_ps(), D_14b2060[28]);
        if (_mm_ucomige_ss(_mm_dp_ps(relativeVelocity, normal, 0x7f), minusTolerance)) {
            continue;
        }
        const Vec4 drift = _mm_dp_ps(relativeVelocity, triangleNormal, 0x7f);
        const Vec4 halfSpeedSquared =
            _mm_mul_ps(D_14b2060[18], _mm_dp_ps(relativeVelocity, relativeVelocity, 0x7f));
        if (_mm_ucomigt_ss(_mm_mul_ps(drift, drift), halfSpeedSquared)) {
            continue;
        }
        const Vec4 correction = _mm_sub_ps(normal, _mm_mul_ps(triangleNormal, cosAngle));
        const Vec4 radius = _mm_set1_ps(cdBodyA.rootShape->convexRadius);
        const Vec4 absCos = hkMath::quadFabs(cosAngle);
        Vec4 minDistance = D_14b2060[33];
        const int numPoints = manifold.numPoints;
        Vec4 *distances = reinterpret_cast<Vec4 *>(manifold.distances);
        for (int p = 0, block = 0; p < numPoints; p += 4, block++) {
            Vec4 &distances4 = distances[block];
            const Vec4 distance = _mm_add_ps(radius, distances4);
            manifold.positions[0].quad = _mm_add_ps(_mm_mul_ps(correction, broadcast<0>(distance)),
                                                    manifold.positions[0].quad);
            manifold.positions[1].quad = _mm_add_ps(_mm_mul_ps(correction, broadcast<1>(distance)),
                                                    manifold.positions[1].quad);
            manifold.positions[2].quad = _mm_add_ps(_mm_mul_ps(correction, broadcast<2>(distance)),
                                                    manifold.positions[2].quad);
            manifold.positions[3].quad = _mm_add_ps(_mm_mul_ps(correction, broadcast<3>(distance)),
                                                    manifold.positions[3].quad);
            const Vec4 newDistance = _mm_sub_ps(_mm_mul_ps(absCos, distance), radius);
            minDistance = _mm_min_ps(minDistance, newDistance);
            distances4 = newDistance;
        }
        manifold.minDistance = _mm_cvtss_f32(horizontalMin<4>(minDistance));
        manifold.normal.quad = triangleNormal;
    }
    stream->timerEnd("Et");
}
