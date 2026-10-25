/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 10 of hkMemoryMeshBody's vtable (0x1691610) sets
 * matrices of its transform set. */
void hkMemoryMeshBody::FUN_00023100(int startIndex, const Mat4 *matrices,
                                    int numMatrices) /* derived name */
{
    FUN_00023700(transformSet, startIndex, matrices, numMatrices);
}
