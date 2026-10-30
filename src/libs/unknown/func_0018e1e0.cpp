/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_types.h"

/* An entry 0x18d960 builds on its stack to sort (derived names): a value
 * and the key it is sorted by, the int at +0x28 of each of its objects. */
struct SortEntry0018d960 /* derived name */
{
    u32 value;
    int key;
};

/* The entries' order, the larger key first. derived name. */
struct KeyGreater0018d960 /* derived name */
{
    bool operator()(const SortEntry0018d960 &a, const SortEntry0018d960 &b) const
    {
        return a.key > b.key;
    }
};

/* The entries' sort (0x18e1e0, called at 0x18db23). */
template void hkAlgorithm::quickSortRecursive(SortEntry0018d960 *pArr, int d, int h,
                                              KeyGreater0018d960 cmpLess);
