/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_algorithm.h"
#include "tlg_hk_reflect.h"

/* The skinned mesh's parts sorted through an order function (0xad970; the
 * storage shape's slot 16, 0xae860, sorts its parts by bone set with
 * FUN_000ad900). */
template void hkAlgorithm::quickSortRecursive(hkSkinnedMeshShape::Part *pArr, int d, int h,
                                              bool (*cmpLess)(const hkSkinnedMeshShape::Part &,
                                                              const hkSkinnedMeshShape::Part &));
