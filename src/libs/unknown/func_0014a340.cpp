/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_lib_unknown.h"

/* The records' sort by key (0x14a990 sorts what it filled, 0x14aa32). */
// NONMATCHING: equal but for the swap's tail copy (key to index, one
// 18-byte memcpy): GVN numbers its source GEP as the i-scan's key GEP and
// replaces it, so the address leaves the loop in a register (`lea r8,
// [r15+rdi+0x30]`), where the base folds [r15+rdi+0x30] into each load;
// the base's source address is a GEP GVN does not merge with the key's
// (the record's declaration, NOTES "Round 75A").
template void hkAlgorithm::quickSortRecursive(SortRecord0014a340 *pArr, int d, int h,
                                              hkAlgorithm::less<SortRecord0014a340> cmpLess);
