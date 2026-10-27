/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the order hkStorageSkinnedMeshShape sorts its parts in (at
 * 0xae86e, passed to the quick sort FUN_000ad970): by bone set. */
bool FUN_000ad900(const hkSkinnedMeshShape::Part &a,
                  const hkSkinnedMeshShape::Part &b) /* derived name */
{
    return a.boneSetId.value < b.boneSetId.value;
}
