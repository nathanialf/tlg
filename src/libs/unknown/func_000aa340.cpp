/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* derived names: a tolerance of 2e-4 in all four lanes and a second vector
 * copied from it (FUN_00048b20 later stores into the second the first scaled
 * by the float at +0xe0 of its object, 0x48daf), both by this file's static initializer FUN_000aa340
 * (`_GLOBAL__I_a`). The initializer reaches them by GOT loads the linker
 * relaxed to `lea` (D10), and other files read them by address
 * (0x48db8, 0x48dc3, 0xaa0f9, 0xfd729): globals of the file. */
hkVector4 D_57c87d0 = {_mm_set1_ps(2e-4f)};
hkVector4 D_57c87e0 = D_57c87d0;

/* The sign bit of each lane of a vector, as a mask to flip another's signs
 * with. derived name. */
static inline Vec4 signBits(const Vec4 &v) /* derived name */
{
    return _mm_castsi128_ps(_mm_slli_epi32(_mm_srli_epi32(_mm_castps_si128(v), 31), 31));
}

int FUN_000a9fc0(const hkcdRay &ray, const Vec4 &a, const Vec4 &b, const Vec4 &c, int flags,
                 Vec4 *fractionInOut, Vec4 *normalOut)
{
    const Vec4 ca = _mm_sub_ps(a, c);
    const Vec4 ab = _mm_sub_ps(b, a);
    const Vec4 normal = cross3(ab, ca);
    const Vec4 toOrigin = _mm_sub_ps(ray.origin, a);
    const Vec4 toEnd = _mm_add_ps(toOrigin, _mm_mul_ps(*fractionInOut, ray.direction));
    const Vec4 distanceStart = _mm_dp_ps(normal, toOrigin, 0x7f);
    const Vec4 distanceEnd = _mm_dp_ps(normal, toEnd, 0x7f);
    if (_mm_ucomige_ss(_mm_mul_ps(distanceStart, distanceEnd), _mm_setzero_ps())) {
        return 0;
    }

    /* The hit: the fraction where the segment crosses the plane, the normal
     * facing the ray's origin. */
    const Vec4 startSign = signBits(distanceStart);
    *normalOut = _mm_xor_ps(normal, startSign);
    const Vec4 denominator = _mm_sub_ps(distanceStart, distanceEnd);
    const Vec4 r = _mm_rcp_ps(denominator);
    const Vec4 invDenominator =
        _mm_mul_ps(r, _mm_sub_ps(_mm_load_ps(D_14b4380), _mm_mul_ps(denominator, r)));
    /* The planes through the ray and each edge. */
    const Vec4 bc = _mm_sub_ps(c, b);
    const Vec4 edgeAB = cross3(ab, ray.direction);
    const Vec4 edgeBC = cross3(bc, ray.direction);
    const Vec4 edgeCA = cross3(ca, ray.direction);
    *fractionInOut = _mm_mul_ps(_mm_mul_ps(distanceStart, invDenominator), *fractionInOut);
    /* Each edge's plane, its distance to the ray's origin against a
     * tolerance that grows with the edge, the ray and the origin's
     * distance from the triangle. */
    const Vec4 lengthsSquared = _mm_or_ps(
        _mm_or_ps(_mm_dp_ps(ab, ab, 0x71), _mm_dp_ps(bc, bc, 0x72)),
        _mm_or_ps(_mm_dp_ps(ca, ca, 0x74), _mm_dp_ps(ray.direction, ray.direction, 0x78)));
    const Vec4 directionLengthSquared = _mm_dp_ps(ray.direction, ray.direction, 0x78);
    /* One for a front face, two for a back face. */
    const int side = (_mm_movemask_ps(_mm_cmplt_ps(distanceStart, _mm_setzero_ps())) & 1) + 1;
    const Vec4 originDistanceSquared = _mm_dp_ps(toOrigin, toOrigin, 0x7f);
    const Vec4 originDistance =
        _mm_mul_ps(originDistanceSquared, _mm_rsqrt_ps(originDistanceSquared));
    const Vec4 twiceOrigin = _mm_add_ps(ray.origin, ray.origin);
    const Vec4 lengths = _mm_mul_ps(lengthsSquared, _mm_rsqrt_ps(lengthsSquared));
    const Vec4 originScale = _mm_add_ps(D_57c87e0.quad, _mm_mul_ps(originDistance, D_14b2060[35]));
    const Vec4 tolerance = _mm_mul_ps(_mm_mul_ps(lengths, broadcast<3>(lengths)),
                                      _mm_add_ps(originScale, originScale));
    const Vec4 edgeDistances =
        _mm_or_ps(_mm_or_ps(_mm_dp_ps(edgeAB, _mm_sub_ps(twiceOrigin, _mm_add_ps(a, b)), 0x71),
                            _mm_dp_ps(edgeBC, _mm_sub_ps(twiceOrigin, _mm_add_ps(b, c)), 0x72)),
                  _mm_dp_ps(edgeCA, _mm_sub_ps(twiceOrigin, _mm_add_ps(a, c)), 0x74));
    const int outside = _mm_movemask_ps(_mm_cmplt_ps(tolerance, edgeDistances));
    const int inside =
        _mm_movemask_ps(_mm_cmplt_ps(edgeDistances, _mm_xor_ps(tolerance, _mm_set1_ps(-0.0f))));
    const int result = ((side >> (inside & 7)) | (side >> (outside & 7))) & ((flags ^ 3) & side);
    if (!(flags & 8)) {
        return result;
    }

    /* A sliver: the longest edge long against the normal's length. */
    const Vec4 normalLengthSquared = _mm_dp_ps(normal, normal, 0x7f);
    const Vec4 normalLength = _mm_mul_ps(normalLengthSquared, _mm_rsqrt_ps(normalLengthSquared));
    const Vec4 maxLength =
        _mm_max_ps(broadcast<2>(lengths), _mm_max_ps(broadcast<1>(lengths), broadcast<0>(lengths)));
    if (_mm_cvtss_f32(_mm_mul_ps(maxLength, maxLength)) <
        _mm_cvtss_f32(_mm_mul_ps(normalLength, _mm_mul_ps(D_14b2060[20], D_14b2060[20])))) {
        return result;
    }

    /* Each vertex's plane through the ray, from its two edges' unit
     * planes, against a tolerance that grows with the origin's
     * distance. */
    const Vec4 edgeLengthsSquared =
        _mm_or_ps(_mm_or_ps(_mm_dp_ps(edgeAB, edgeAB, 0x71), _mm_dp_ps(edgeBC, edgeBC, 0x72)),
                  _mm_dp_ps(edgeCA, edgeCA, 0x74));
    const Vec4 half = _mm_load_ps(D_14b4360);
    const Vec4 three = _mm_load_ps(D_14b4390);
    const Vec4 e = _mm_rsqrt_ps(edgeLengthsSquared);
    const Vec4 invEdgeLengths = _mm_andnot_ps(
        _mm_cmple_ps(edgeLengthsSquared, _mm_setzero_ps()),
        _mm_mul_ps(_mm_mul_ps(e, half),
                   _mm_sub_ps(three, _mm_mul_ps(edgeLengthsSquared, _mm_mul_ps(e, e)))));
    const Vec4 vertexTolerance = _mm_add_ps(
        D_57c87e0.quad, _mm_mul_ps(originDistance, _mm_mul_ps(D_14b2060[35], D_14b2060[4])));
    const Vec4 unitAB = _mm_mul_ps(edgeAB, broadcast<0>(invEdgeLengths));
    const Vec4 unitBC = _mm_mul_ps(edgeBC, broadcast<1>(invEdgeLengths));
    const Vec4 unitCA = _mm_mul_ps(edgeCA, broadcast<2>(invEdgeLengths));
    const Vec4 vertexA = _mm_add_ps(unitCA, unitAB);
    const Vec4 vertexB = _mm_add_ps(unitAB, unitBC);
    const Vec4 vertexC = _mm_add_ps(unitBC, unitCA);
    const Vec4 vertexLengthsSquared =
        _mm_or_ps(_mm_or_ps(_mm_dp_ps(vertexA, vertexA, 0x71), _mm_dp_ps(vertexB, vertexB, 0x72)),
                  _mm_or_ps(_mm_dp_ps(vertexC, vertexC, 0x74), directionLengthSquared));
    const Vec4 vertexLengths = _mm_mul_ps(_mm_rsqrt_ps(vertexLengthsSquared), vertexLengthsSquared);
    const Vec4 vertexDistances =
        _mm_xor_ps(_mm_or_ps(_mm_or_ps(_mm_dp_ps(vertexA, _mm_sub_ps(ray.origin, a), 0x71),
                                       _mm_dp_ps(vertexB, _mm_sub_ps(ray.origin, b), 0x72)),
                             _mm_dp_ps(vertexC, _mm_sub_ps(ray.origin, c), 0x74)),
                   startSign);
    if (_mm_movemask_ps(_mm_cmplt_ps(_mm_mul_ps(vertexTolerance, vertexLengths), vertexDistances)) &
        7) {
        return 0;
    }
    return result;
}
