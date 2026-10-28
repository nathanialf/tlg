/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The single-cell splitter: kind 0, one cell, and the one pair of that cell
 * with itself. */
SpaceSplitter00060b90::SpaceSplitter00060b90() : hknpSpaceSplitter(0)
{
    numCells = 1;
    numCellPairs = 1;
    cellPairs.setSize(1);
    cellPairs[0] = 0;
}
