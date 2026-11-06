/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* The magnitude of each lane (hkMath::fabs's form, cookbook 70). derived
 * name. */
static inline Vec4 absLanes(const Vec4 &v) /* derived name */
{
    const __m128i bits = _mm_castps_si128(v);
    return _mm_castsi128_ps(_mm_srli_epi32(_mm_add_epi32(bits, bits), 1));
}

/* Whether a comparison holds in x, y and z (hkVector4Comparison's
 * allAreSet on the three lanes). derived name. */
static inline bool allXYZ(const Vec4 &comparison) /* derived name */
{
    const __m128 xyz = _mm_blend_ps(_mm_setzero_ps(), _mm_castsi128_ps(_mm_set1_epi32(-1)), 7);
    return _mm_testc_si128(_mm_castps_si128(_mm_and_ps(comparison, xyz)), _mm_castps_si128(xyz));
}

/* A convex shape's scaling: the scale kept above 0.001; a sphere or a
 * capsule (types 2 and 3) scaled uniformly by x, its radius with it; any
 * other shape, in the radius-keeping mode with a radius and a scale other
 * than one, has its vertices' box grown by the radius and scaled, the
 * radius shrunk to fit the smallest scaled half extent, and the scale and
 * the offset adjusted so the scaled shape keeps its size. */
void FUN_00169c90(int shapeType, const Vec4 *vertices, int numVertices, int scaleMode,
                  Vec4 &scaleInOut, float &radiusInOut, Vec4 &offsetOut)
{
    const Vec4 originalScale = scaleInOut;
    Vec4 scale = _mm_max_ps(originalScale, _mm_set1_ps(0.001f));
    if ((shapeType & ~1) == 2) {
        /* A sphere or a capsule scales uniformly, by x. */
        radiusInOut = _mm_cvtss_f32(scale) * radiusInOut;
        offsetOut = _mm_setzero_ps();
        scale = _mm_shuffle_ps(scale, scale, _MM_SHUFFLE(0, 0, 0, 0));
    } else {
        const float radius = radiusInOut;
        if (scaleMode == 0 && _mm_ucomigt_ss(absLanes(_mm_set_ss(radius)), _mm_set1_ps(1e-5f)) &&
            !allXYZ(_mm_cmple_ps(absLanes(_mm_sub_ps(scale, D_14b2060[3])), D_14b2060[35]))) {
            hkAabb bounds;
            bounds.setEmpty();
            const Vec4 *v = vertices;
            for (int i = 0; i < numVertices; i += 4) {
                bounds.includePoint(v[0]);
                bounds.includePoint(v[1]);
                bounds.includePoint(v[2]);
                bounds.includePoint(v[3]);
                v += 4;
            }
            const Vec4 halfExtents = _mm_mul_ps(_mm_sub_ps(bounds.max, bounds.min), D_14b2060[18]);
            const Vec4 center = _mm_mul_ps(_mm_add_ps(bounds.max, bounds.min), D_14b2060[18]);
            /* The radius read again after the vertices' walk: its splat
             * ranks above the bounds, so Reassociate keeps the extents
             * and the scale first in the sum and the product (0x169dac,
             * 0x169de8). */
            const Vec4 radiusV = simdFromFloat(radiusInOut);
            const Vec4 absScale = absLanes(scale);
            const Vec4 scaledExtents = _mm_mul_ps(absScale, _mm_add_ps(halfExtents, radiusV));
            Vec4 newRadius = radiusV;
            if (!allXYZ(_mm_cmplt_ps(radiusV, scaledExtents))) {
                newRadius = _mm_min_ps(
                    _mm_shuffle_ps(scaledExtents, scaledExtents, _MM_SHUFFLE(2, 2, 2, 2)),
                    _mm_min_ps(
                        _mm_shuffle_ps(scaledExtents, scaledExtents, _MM_SHUFFLE(1, 1, 1, 1)),
                        _mm_shuffle_ps(scaledExtents, scaledExtents, _MM_SHUFFLE(0, 0, 0, 0))));
            }
            const Vec4 delta = _mm_sub_ps(_mm_mul_ps(absScale, radiusV), newRadius);
            const Vec4 r = _mm_rcp_ps(halfExtents);
            const Vec4 inverse = _mm_mul_ps(r, _mm_sub_ps(D_14b4380, _mm_mul_ps(halfExtents, r)));
            radiusInOut = _mm_cvtss_f32(newRadius);
            const Vec4 grow = _mm_andnot_ps(_mm_cmpeq_ps(halfExtents, _mm_setzero_ps()),
                                            _mm_mul_ps(delta, inverse));
            offsetOut = _mm_mul_ps(_mm_xor_ps(center, _mm_set_ps(0.0f, -0.0f, -0.0f, -0.0f)), grow);
            scale = _mm_max_ps(_mm_add_ps(scale, grow), _mm_set1_ps(0.001f));
        } else {
            offsetOut = _mm_setzero_ps();
        }
    }
    scaleInOut = _mm_blend_ps(scale, originalScale, 8);
}
