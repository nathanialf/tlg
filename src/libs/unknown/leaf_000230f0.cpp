/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 9 of hkMemoryMeshBody's vtable (0x1691610) counts the
 * matrices of its transform set, none without one. */
int hkMemoryMeshBody::FUN_000230f0() const /* derived name */
{
    return transformSet ? transformSet->matrices.size : 0;
}
