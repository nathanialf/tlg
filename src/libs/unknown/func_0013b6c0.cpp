/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_lib_unknown.h"

/* The leaves' ages sorted (the layer tree update 0x13e090 builds them,
 * 0x13e5d0, and sorts them, 0x13e62b). */
template void hkAlgorithm::quickSortRecursive<LeafAge0013b6c0, hkAlgorithm::less<LeafAge0013b6c0>>(
    LeafAge0013b6c0 *, int, int, hkAlgorithm::less<LeafAge0013b6c0>);
