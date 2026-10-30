/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"

/* The pointer sort's instantiation (0x1630's collected pointers, sorted by
 * address). */
template void hkAlgorithm::quickSortRecursive(void **pArr, int d, int h,
                                              hkAlgorithm::less<void *> cmpLess);
