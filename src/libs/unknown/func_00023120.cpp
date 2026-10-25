/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 12 of hkMemoryMeshBody's vtable (0x1691610) reads
 * inverse matrices of its transform set. */
void hkMemoryMeshBody::FUN_00023120(int startIndex, Mat4 *matrices,
                                    int numMatrices) const /* derived name */
{
    FUN_000237b0(transformSet, startIndex, matrices, numMatrices);
}
