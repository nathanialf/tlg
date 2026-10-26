/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 16 of hkMemoryMeshBody's vtable (0x1691610) counts the
 * index mappings of its transform set, none without one. */
int hkMemoryMeshBody::FUN_00023160() const /* derived name */
{
    return transformSet ? transformSet->indexMappings.size : 0;
}
