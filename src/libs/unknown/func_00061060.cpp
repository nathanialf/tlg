/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_lib_unknown.h"

/* The library's table of integer vector constants (derived name), extern,
 * reached through its GOT slot: row 4 (+0x40) is 4 in each lane, row 5
 * (+0x50) the lanes' indices 0 to 3. */
extern const __m128i D_14c44b0[6];

/* The squared distances from a position to four points, lane i the i-th
 * point's (derived name). */
static inline Vec4 squaredDistances(const Vec4 &position, const Vec4 *points)
{
    const Vec4 d3 = _mm_sub_ps(points[3], position);
    const Vec4 d2 = _mm_sub_ps(points[2], position);
    const Vec4 d1 = _mm_sub_ps(points[1], position);
    const Vec4 d0 = _mm_sub_ps(points[0], position);
    const Vec4 upper = _mm_or_ps(_mm_dp_ps(d2, d2, 0x74), _mm_dp_ps(d3, d3, 0x78));
    const Vec4 lower = _mm_or_ps(_mm_dp_ps(d0, d0, 0x71), _mm_dp_ps(d1, d1, 0x72));
    return _mm_or_ps(lower, upper);
}

/* The points four at a time, each lane keeping its nearest point and that
 * point's index, then the nearest of the four lanes. */
void FlaggedPoints00060c70::FUN_00061060(const Vec4 &position, int *cellOut) const
{
    const Vec4 p = position;
    Vec4 best = squaredDistances(p, points);
    __m128i bestIndex = D_14c44b0[5];
    __m128i index = bestIndex;
    for (int i = 4; i < numCells; i += 4) {
        const Vec4 distances = squaredDistances(p, &points[i]);
        const Vec4 keep = _mm_cmplt_ps(best, distances);
        index = _mm_add_epi32(index, D_14c44b0[4]);
        best = _mm_blendv_ps(distances, best, keep);
        bestIndex = _mm_blendv_epi8(index, bestIndex, _mm_castps_si128(keep));
    }
    const Vec4 swapped = _mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(best), 0x4e));
    const Vec4 keep0 = _mm_cmplt_ps(best, swapped);
    const Vec4 best2 = _mm_blendv_ps(swapped, best, keep0);
    const Vec4 rotated = _mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(best2), 0x39));
    const Vec4 keep1 = _mm_cmplt_ps(best2, rotated);
    const __m128i index2 =
        _mm_blendv_epi8(_mm_shuffle_epi32(bestIndex, 0x4e), bestIndex, _mm_castps_si128(keep0));
    const __m128i index1 =
        _mm_blendv_epi8(_mm_shuffle_epi32(index2, 0x39), index2, _mm_castps_si128(keep1));
    _mm_store_ss(reinterpret_cast<float *>(cellOut), _mm_castsi128_ps(index1));
}
