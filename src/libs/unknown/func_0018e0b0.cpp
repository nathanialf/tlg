/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_types.h"

/* A second entry 0x18d960 builds on its stack to sort (derived names), 16
 * bytes: its index, two ids and the key it is sorted by, the sum of the
 * ints at +0x28 of the two ids' objects (0x18dca0 to 0x18dcd9). */
struct PairSortEntry0018d960 /* derived name */
{
    int index;
    int idA;
    int idB;
    int key;
};

/* The entries' order, the larger key first. derived name. */
struct PairKeyGreater0018d960 /* derived name */
{
    bool operator()(const PairSortEntry0018d960 &a, const PairSortEntry0018d960 &b) const
    {
        return a.key > b.key;
    }
};

// NONMATCHING: the first scan's key load kept apart from its compare (`mov
// ebx; cmp ebx, r8d`, the base folds it), so one register fewer: the stack
// guard's address is loaded again at the end where the base keeps it in
// r12; and the second scan's two induction increments in the other order,
// as in 0x72980 (docs/NOTES.md, Round 63A).
/* The entries' sort (0x18e0b0, called at 0x18dcf8). */
template void hkAlgorithm::quickSortRecursive(PairSortEntry0018d960 *pArr, int d, int h,
                                              PairKeyGreater0018d960 cmpLess);
