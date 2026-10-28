/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Kind 1: the points laid out four to a row, none flagged, then the cell
 * counts and the pairs. */
FlaggedPoints00060c70::FlaggedPoints00060c70(int numPoints) : hknpSpaceSplitter(1)
{
    unknown24 = 0;
    for (int i = 0; i < numPoints; i++) {
        const float row = float(i / 4);
        points[i] = _mm_setr_ps(float(i % 4) * 10.0f, row * 10.0f, row * 5.0f, 0.0f);
        flags[i] = 0;
    }
    numCells = numPoints;
    numCellPairs = (numPoints * (numPoints + 1)) >> 1;
    FUN_00060a10(numPoints);
}
