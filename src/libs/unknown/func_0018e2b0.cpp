/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_types.h"

/* The sort of 16-bit values by the default order (0x18e2b0; the grid space
 * splitter's 0x18e3e0 sorts its keys with it). */
template void hkAlgorithm::quickSortRecursive<u16, hkAlgorithm::less<u16>>(u16 *, int, int,
                                                                           hkAlgorithm::less<u16>);
