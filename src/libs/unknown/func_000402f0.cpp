/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"
#include "tlg_hk_algorithm.h"

/* The byte sort's instantiation (0x3fa40's three array indices, ordered by
 * their accesses' ids). */
template void hkAlgorithm::quickSortRecursive(u8 *pArr, int d, int h,
                                              SolverArrays0003f820::AccessIdLess cmpLess);
