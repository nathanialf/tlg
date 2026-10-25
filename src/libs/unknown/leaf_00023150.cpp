/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 15 of hkMemoryMeshBody's vtable (0x1691610) returns
 * its transform set's indexMappings. */
const hkMeshBoneIndexMapping *hkMemoryMeshBody::FUN_00023150() const /* derived name */
{
    return transformSet->indexMappings.data;
}
