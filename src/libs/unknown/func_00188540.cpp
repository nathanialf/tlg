/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"
#include "tlg_simd.h"

/* The library's vector constants (derived names): a table of splatted
 * values at 0x14b2060 (zero at +0x20, one at +0x30, the largest float at
 * +0x210 and its negation at +0x260), splats of 0.5, 2 and 3, the masks of
 * a comparison by its four bits (row m at element 4 * m) and the index of
 * the highest set bit of a four-bit mask. */
extern const Vec4 D_14b2060[];
extern const Vec4 D_14b4360;
extern const Vec4 D_14b4380;
extern const Vec4 D_14b4390;
extern const u32 D_14b7220[];
extern const u8 D_14c4160[];

/* derived name: a tolerance of 1e-4 in all four lanes, set by this file's
 * static initializer FUN_00188540 and read by FUN_00187750 at 0x187fae and
 * 0x18847d. It is file-local: the base stores to it and reads it
 * RIP-relative, with no GOT load (D17). */
static Vec4 D_57c8990 = _mm_set1_ps(1e-4f);

/* derived names below: the vector operations the function is written in. */
static inline Vec4 FUN_broadcast(Vec4 v, int i)
{
    return _mm_castsi128_ps(
        _mm_shuffle_epi8(_mm_castps_si128(v), _mm_set1_epi32(i * 0x04040404 + 0x03020100)));
}

static inline Vec4 FUN_maskOf(int bits)
{
    return _mm_load_ps((const float *)&D_14b7220[bits * 4]);
}

static inline Vec4 FUN_dot4_1vs4(Vec4 v, Vec4 a0, Vec4 a1, Vec4 a2, Vec4 a3)
{
    const Vec4 d0 = _mm_dp_ps(v, a0, 0xF1);
    const Vec4 d1 = _mm_dp_ps(v, a1, 0xF2);
    const Vec4 d2 = _mm_dp_ps(v, a2, 0xF4);
    const Vec4 d3 = _mm_dp_ps(v, a3, 0xF8);
    return _mm_or_ps(_mm_or_ps(d0, d1), _mm_or_ps(d2, d3));
}

/* The index of the largest of the four lanes (the last when several are). */
static inline int FUN_indexOfMax4(Vec4 v)
{
    const Vec4 s0 = _mm_max_ps(_mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 0, 3, 2)), v);
    const Vec4 s1 = _mm_max_ps(s0, _mm_shuffle_ps(s0, s0, _MM_SHUFFLE(2, 3, 0, 1)));
    const Vec4 m = _mm_shuffle_ps(s1, s1, _MM_SHUFFLE(0, 0, 0, 0));
    return D_14c4160[_mm_movemask_ps(_mm_cmple_ps(m, v))];
}

/* The index of the smallest of the first three lanes (the last when several
 * are), by the largest of their negations. */
static inline int FUN_indexOfMin3(Vec4 v)
{
    const Vec4 n = _mm_xor_ps(v, _mm_castsi128_ps(_mm_set1_epi32(0x80000000)));
    const Vec4 xy = _mm_max_ps(_mm_shuffle_ps(n, n, _MM_SHUFFLE(1, 1, 1, 1)),
                               _mm_shuffle_ps(n, n, _MM_SHUFFLE(0, 0, 0, 0)));
    const Vec4 m = _mm_max_ps(_mm_shuffle_ps(n, n, _MM_SHUFFLE(2, 2, 2, 2)), xy);
    const Vec4 xyz = _mm_castsi128_ps(_mm_setr_epi32(-1, -1, -1, 0));
    return D_14c4160[_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(m, n), xyz))];
}

static inline Vec4 FUN_cross(Vec4 a, Vec4 b)
{
    const Vec4 c0 = _mm_mul_ps(a, _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1)));
    const Vec4 c1 = _mm_mul_ps(_mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1)), b);
    const Vec4 d = _mm_sub_ps(c0, c1);
    return _mm_shuffle_ps(d, d, _MM_SHUFFLE(3, 0, 2, 1));
}

/* m * v over the first three lanes of v. */
static inline Vec4 FUN_rotate(const hkMatrix3 &m, Vec4 v)
{
    const Vec4 r0 = _mm_mul_ps(m.col0, _mm_shuffle_ps(v, v, _MM_SHUFFLE(0, 0, 0, 0)));
    const Vec4 r1 = _mm_mul_ps(m.col1, _mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 1, 1, 1)));
    const Vec4 r2 = _mm_mul_ps(m.col2, _mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 2, 2, 2)));
    return _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

/* The transpose of m times v over the first three lanes of v. */
static inline Vec4 FUN_rotateInverse(const hkMatrix3 &m, Vec4 v)
{
    Vec4 a = m.col0;
    Vec4 b = m.col1;
    Vec4 c = m.col2;
    const Vec4 lo = _mm_unpacklo_ps(a, b);
    const Vec4 hi = _mm_unpackhi_ps(a, b);
    a = _mm_movelh_ps(lo, c);
    b = _mm_shuffle_ps(_mm_movehl_ps(lo, lo), c, _MM_SHUFFLE(3, 1, 1, 0));
    c = _mm_shuffle_ps(hi, c, _MM_SHUFFLE(3, 2, 1, 0));
    const hkMatrix3 t = {a, b, c};
    return FUN_rotate(t, v);
}

/* The plane of the set farthest above the point (x, y, z, 1): its distance
 * is returned and planeOut is the plane. */
static inline Vec4 FUN_farthestPlane(Vec4 point, const Vec4 *planes, int numPlanes, Vec4 &planeOut)
{
    planeOut = _mm_blend_ps(_mm_setzero_ps(), D_14b2060[38], 8);
    for (int i = numPlanes >> 2; i > 0; i--) {
        const Vec4 dists = FUN_dot4_1vs4(point, planes[0], planes[1], planes[2], planes[3]);
        const int index = FUN_indexOfMax4(dists);
        const Vec4 dist = FUN_broadcast(dists, index);
        const Vec4 candidate = _mm_blend_ps(planes[index], dist, 8);
        const Vec4 farther =
            _mm_cmplt_ps(_mm_shuffle_ps(planeOut, planeOut, _MM_SHUFFLE(3, 3, 3, 3)), dist);
        planeOut = _mm_blendv_ps(planeOut, candidate, farther);
        planes += 4;
    }
    for (int i = numPlanes & 3; i > 0; i--) {
        const Vec4 dist = _mm_dp_ps(*planes, point, 0xFF);
        const Vec4 farther =
            _mm_cmplt_ps(_mm_shuffle_ps(planeOut, planeOut, _MM_SHUFFLE(3, 3, 3, 3)), dist);
        planeOut = _mm_blendv_ps(planeOut, _mm_blend_ps(*planes, dist, 8), farther);
        planes++;
    }
    const Vec4 dist = _mm_shuffle_ps(planeOut, planeOut, _MM_SHUFFLE(3, 3, 3, 3));
    planeOut = _mm_blend_ps(planeOut, _mm_sub_ps(dist, _mm_dp_ps(planeOut, point, 0x7F)), 8);
    return dist;
}

/* derived name: the point of the convex region below a set of planes
 * (normal and offset, four to a block) closest to a point, by an active set
 * of at most three planes: the point projected onto them (one plane, the
 * line two meet in, the vertex of three by the inverse FUN_0001ae40), a
 * plane dropped while its weight is negative, the farthest violated plane
 * added, for at most maxIterations rounds. Writes the closest point, the
 * direction and the distance to it (negative inside the first plane when
 * one round sufficed) and the rounds taken; true unless the point is
 * farther from the region than the tolerance. */
// NONMATCHING: the base loads the stack canary (0x18777c) and checks it before
// the return (0x187a0e, __stack_chk_fail at 0x188536) in a frame of 0x1c8;
// under the prefix's -fstack-protector LLVM 3.3 protects only a function with
// a char array of 8 bytes or more (StackProtector.cpp,
// ContainsProtectableArray), which this one has none of, so it compiles
// without a canary (frame 0x198, 2274 bytes against 3564; the base also
// unswitches the second search on numPlanes >= 4). A classified note,
// docs/NOTES.md Round 20.
bool FUN_00187750(const Vec4 &point, const Vec4 *planes, int numPlanes,
                  const Vec4 &toleranceSquared, int maxIterations, Vec4 &closestOut,
                  Vec4 &normalOut, Vec4 &distanceOut, int *numIterationsOut)
{
    const Vec4 minusMax = D_14b2060[38];
    const Vec4 point1 = _mm_blend_ps(point, D_14b2060[3], 8);
    const Vec4 noPlane = _mm_setr_ps(0.0f, 0.0f, 0.0f, 3.40282e38f);
    Vec4 simplex[3];
    FUN_farthestPlane(point1, planes, numPlanes, simplex[0]);
    simplex[1] = noPlane;
    simplex[2] = noPlane;
    const Vec4 dist = _mm_dp_ps(simplex[0], point1, 0xFF);
    bool outside = _mm_cvtss_f32(_mm_mul_ps(dist, dist)) > _mm_cvtss_f32(toleranceSquared) &&
                   _mm_cvtss_f32(dist) > 0.0f;
    *numIterationsOut = 1;
    Vec4 closest;
    if (maxIterations < 2 || outside) {
        closest = _mm_sub_ps(point, _mm_mul_ps(dist, simplex[0]));
    } else {
        closest = _mm_setzero_ps();
        Vec4 lambdas = _mm_setzero_ps();
        int numSimplex = 1;
        for (*numIterationsOut = 1; *numIterationsOut <= maxIterations; (*numIterationsOut)++) {
            const Vec4 dists = FUN_dot4_1vs4(point1, simplex[0], simplex[1], simplex[2], noPlane);
            switch (numSimplex) {
            case 1:
                closest = _mm_sub_ps(
                    point1,
                    _mm_mul_ps(simplex[0], _mm_shuffle_ps(dists, dists, _MM_SHUFFLE(0, 0, 0, 0))));
                lambdas = _mm_blend_ps(D_14b2060[2], minusMax, 6);
                break;
            case 2: {
                const Vec4 c = FUN_cross(simplex[0], simplex[1]);
                const Vec4 len2 = _mm_dp_ps(c, c, 0x7F);
                const Vec4 r = _mm_rcp_ps(len2);
                const Vec4 rcp = _mm_mul_ps(r, _mm_sub_ps(D_14b4380, _mm_mul_ps(len2, r)));
                const Vec4 invLen2 = _mm_andnot_ps(_mm_cmpeq_ps(len2, _mm_setzero_ps()), rcp);
                hkMatrix3 m;
                m.col0 = _mm_mul_ps(FUN_cross(simplex[1], c), invLen2);
                m.col1 = _mm_mul_ps(FUN_cross(c, simplex[0]), invLen2);
                m.col2 = _mm_mul_ps(c, invLen2);
                const Vec4 zero = _mm_setzero_ps();
                const Vec4 w0 = _mm_sub_ps(
                    zero, _mm_shuffle_ps(simplex[0], simplex[0], _MM_SHUFFLE(3, 3, 3, 3)));
                const Vec4 w1 = _mm_sub_ps(
                    zero, _mm_shuffle_ps(simplex[1], simplex[1], _MM_SHUFFLE(3, 3, 3, 3)));
                const Vec4 cp = _mm_dp_ps(c, point1, 0x7F);
                const Vec4 rhs = _mm_movelh_ps(_mm_unpacklo_ps(w0, w1), _mm_unpacklo_ps(cp, zero));
                closest = FUN_rotate(m, rhs);
                lambdas =
                    _mm_blend_ps(FUN_rotateInverse(m, _mm_sub_ps(point1, closest)), minusMax, 4);
                break;
            }
            case 3: {
                const hkMatrix3 m = {simplex[0], simplex[1], simplex[2]};
                hkMatrix3 inverse;
                inverse.FUN_0001ae40(m);
                const Vec4 w = _mm_movelh_ps(
                    _mm_unpacklo_ps(
                        _mm_shuffle_ps(simplex[0], simplex[0], _MM_SHUFFLE(3, 3, 3, 3)),
                        _mm_shuffle_ps(simplex[1], simplex[1], _MM_SHUFFLE(3, 3, 3, 3))),
                    _mm_unpacklo_ps(_mm_shuffle_ps(simplex[2], simplex[2], _MM_SHUFFLE(3, 3, 3, 3)),
                                    D_14b2060[2]));
                const Vec4 rhs = _mm_xor_ps(w, _mm_castsi128_ps(_mm_set1_epi32(0x80000000)));
                closest = FUN_rotate(inverse, rhs);
                lambdas = FUN_rotate(inverse, _mm_sub_ps(point1, closest));
                break;
            }
            }

            /* drop the plane of the nearest negative weight */
            const Vec4 negative = _mm_cmplt_ps(lambdas, _mm_setzero_ps());
            const Vec4 max = D_14b2060[33];
            const Vec4 masked = _mm_blendv_ps(max, dists, negative);
            const int last = numSimplex - 1;
            const Vec4 lastMask = FUN_maskOf(1 << last);
            const Vec4 lastLambda = FUN_broadcast(lambdas, last);
            const int drop = FUN_indexOfMin3(masked);
            const Vec4 remove = _mm_cmplt_ps(FUN_broadcast(masked, drop), max);
            simplex[drop] = _mm_blendv_ps(simplex[drop], simplex[last], remove);
            simplex[last] = _mm_blendv_ps(simplex[last], noPlane, remove);
            Vec4 moved = _mm_blendv_ps(lambdas, lastLambda, FUN_maskOf(1 << drop));
            moved = _mm_blendv_ps(moved, minusMax, lastMask);
            lambdas = _mm_blendv_ps(lambdas, moved, remove);
            const int removed = _mm_movemask_ps(remove);
            numSimplex -= removed & 1;

            /* add the plane farthest above the closest point */
            Vec4 plane;
            const Vec4 planeDist =
                FUN_farthestPlane(_mm_blend_ps(closest, D_14b2060[3], 8), planes, numPlanes, plane);
            const Vec4 add = _mm_cmplt_ps(D_57c8990, planeDist);
            const Vec4 reversed = _mm_shuffle_ps(lambdas, lambdas, _MM_SHUFFLE(3, 0, 1, 2));
            const int slot = 2 - FUN_indexOfMin3(reversed);
            simplex[slot] = _mm_blendv_ps(simplex[slot], plane, add);
            const int added = _mm_movemask_ps(add);

            const Vec4 d = _mm_sub_ps(point, closest);
            outside = _mm_cvtss_f32(_mm_dp_ps(d, d, 0x7F)) > _mm_cvtss_f32(toleranceSquared);
            if ((removed | added) == 0 || outside) {
                break;
            }
            numSimplex += added & (numSimplex < 3);
        }
    }
    closestOut = closest;
    const Vec4 d = _mm_sub_ps(point, closestOut);
    const Vec4 len2 = _mm_dp_ps(d, d, 0x7F);
    const Vec4 e = _mm_rsqrt_ps(len2);
    const Vec4 invLen =
        _mm_andnot_ps(_mm_cmple_ps(len2, _mm_setzero_ps()),
                      _mm_mul_ps(_mm_mul_ps(e, D_14b4360),
                                 _mm_sub_ps(D_14b4390, _mm_mul_ps(len2, _mm_mul_ps(e, e)))));
    distanceOut = _mm_mul_ps(len2, invLen);
    normalOut = _mm_mul_ps(d, invLen);
    if (*numIterationsOut <= 1) {
        const Vec4 s = _mm_add_ps(_mm_dp_ps(simplex[0], point, 0x7F),
                                  _mm_shuffle_ps(simplex[0], simplex[0], _MM_SHUFFLE(3, 3, 3, 3)));
        if (_mm_cvtss_f32(s) < 0.0f) {
            distanceOut = _mm_sub_ps(_mm_setzero_ps(), distanceOut);
        }
    }
    return !outside;
}
