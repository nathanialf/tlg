/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_types.h"

/* An entry the grid space splitter 0x18e3e0 builds (0x18e680, derived
 * names): the sum of the counts at +0xc along a cell's list, nonzero, and
 * the cell's index. */
struct CellCount0018f290 /* derived name */
{
    int count;
    int index;
};

/* The entries' order, the larger count first. derived name. */
struct CountGreater0018f290 /* derived name */
{
    bool operator()(const CellCount0018f290 &a, const CellCount0018f290 &b) const
    {
        return a.count > b.count;
    }
};

/* The entries' sort (0x18f290, called at 0x18e6e3). */
template void hkAlgorithm::quickSortRecursive(CellCount0018f290 *pArr, int d, int h,
                                              CountGreater0018f290 cmpLess);
