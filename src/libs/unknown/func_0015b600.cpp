/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_types.h"

/* The 32-bit word sort's instantiation (0x15b8e0's call at 0x15bb3c). */
template void hkAlgorithm::quickSortRecursive(u32 *pArr, int d, int h,
                                              hkAlgorithm::less<u32> cmpLess);
