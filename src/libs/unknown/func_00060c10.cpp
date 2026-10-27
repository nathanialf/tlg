/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

void hknpGridSpaceSplitter::FUN_00060c10(const Vec4 &position,
                                         int *cellOut) const /* derived name */
{
    const Vec4 p = position;
    const int x =
        _mm_cvtsi128_si32(_mm_cvttps_epi32(_mm_add_ps(_mm_dp_ps(p, axisX, 0x7f), offsetX))) &
        cellMask;
    const int y =
        _mm_cvtsi128_si32(_mm_cvttps_epi32(_mm_add_ps(_mm_dp_ps(p, axisY, 0x7f), offsetY))) &
        cellMask;
    *cellOut = y * numCellsPerRow + x;
}
