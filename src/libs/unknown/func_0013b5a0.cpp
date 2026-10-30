/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"
#include "tlg_hk_algorithm.h"

/* The boxes' sort by their minimum x (0x13de80 and 0x196720 sort with it). */
// NONMATCHING (0x13b5a0, NOTES Round 64B): equal in every instruction's operation; the pivot's
// row pointer and the scan index trade registers (r13 and r12) and the second scan's two
// increments come in the other order. When it matches, the row is renamed to the
// instantiation's mangled name (cookbook 206).
template void hkAlgorithm::quickSortRecursive(hkAabb16 *pArr, int d, int h,
                                              hkAlgorithm::less<hkAabb16> cmpLess);
