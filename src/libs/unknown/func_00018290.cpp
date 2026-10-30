/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_types.h"

/* The pointers' sort through a comparison function (0x18290; the free
 * list's block check 0x189d0 sorts its blocks by address with
 * FUN_00018280, 0x18af4). */
template void hkAlgorithm::quickSortRecursive(void **pArr, int d, int h,
                                              bool (*cmpLess)(const void *, const void *));
