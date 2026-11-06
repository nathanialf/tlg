/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

/* x, y and z of a times b summed, each product rounded to a float before the
 * sum. derived name. */
static inline float dot3Exact(const Vec4 &a, const Vec4 &b) /* derived name */
{
    /* volatile, each product: kept as a stored float, so the collinearity
     * test below compares exactly rounded values. */
    volatile float x = lane(a, 0) * lane(b, 0);
    volatile float y = lane(a, 1) * lane(b, 1); /* volatile: as x */
    volatile float z = lane(a, 2) * lane(b, 2); /* volatile: as x */
    return x + y + z;
}

/* A triangle is degenerate when either corner's cross product of its edges
 * is shorter than the tolerance, or when two edges are collinear: the
 * product of their squared lengths equals their squared dot product. A
 * negative tolerance finds nothing degenerate. */
int FUN_00185520(const Vec4 &vertex0, const Vec4 &vertex1, const Vec4 &vertex2,
                 const Vec4 &tolerance)
{
    if (_mm_ucomigt_ss(_mm_setzero_ps(), tolerance)) {
        return 0;
    }
    const Vec4 edge01 = _mm_sub_ps(vertex0, vertex1);
    const Vec4 edge02 = _mm_sub_ps(vertex0, vertex2);
    const Vec4 cross0 = cross3(edge01, edge02);
    const Vec4 edge10 = _mm_sub_ps(vertex1, vertex0);
    const Vec4 edge12 = _mm_sub_ps(vertex1, vertex2);
    const Vec4 cross1 = cross3(edge10, edge12);
    const Vec4 small = _mm_or_ps(_mm_cmplt_ps(_mm_dp_ps(cross0, cross0, 0x7f), tolerance),
                                 _mm_cmplt_ps(_mm_dp_ps(cross1, cross1, 0x7f), tolerance));
    if (_mm_testc_si128(_mm_castps_si128(small), _mm_set1_epi32(-1))) {
        return 1;
    }
    const Vec4 edge21 = _mm_sub_ps(vertex2, vertex1);
    const float lengthSquared01 = dot3Exact(edge01, edge01);
    const float lengthSquared21 = dot3Exact(edge21, edge21);
    const float dot = dot3Exact(edge01, edge21);
    /* volatile: as in dot3Exact. */
    volatile float lengthsSquared = lengthSquared01 * lengthSquared21;
    volatile float dotSquared = dot * dot; /* volatile: as above */
    return lengthsSquared - dotSquared == 0.0f;
}
