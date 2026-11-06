/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Every pair of cells, the first i and the second j from i on, made in a
 * temporary array as the two bytes j - i and j; the splitter's pairs are
 * sized to them and filled in its order by 0x606d0 (the pair a two-byte
 * record built field by field, which keeps the copy's 16-bit value made
 * after the array's grow). */
void hknpSpaceSplitter::FUN_00060a10(int numCells)
{
    hkArray<CellPair00060a10> pairs;
    for (int i = 0; i < numCells; i++) {
        for (int j = i, k = 0; j < numCells; j++, k++) {
            CellPair00060a10 pair;
            pair.offset = u8(k);
            pair.cell = u8(j);
            pairs.pushBack(pair);
        }
    }
    const int numPairs = (numCells * (numCells + 1)) >> 1;
    cellPairs.setSize(pairs.getSize());
    FUN_000606d0(numCells, numPairs, pairs.data, cellPairs.data);
}
