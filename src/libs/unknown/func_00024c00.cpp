/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_hk_reflect.h"

/* The locked elements' sort (0x24c00), by the order 0x24b60 gives: the
 * lock (0x25700) sorts its elements with it at 0x257f2. */
template void
hkAlgorithm::quickSortRecursive(hkMultipleVertexBuffer::LockedElement *pArr, int d, int h,
                                bool (*cmpLess)(const hkMultipleVertexBuffer::LockedElement &,
                                                const hkMultipleVertexBuffer::LockedElement &));
