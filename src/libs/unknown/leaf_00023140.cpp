/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 14 of hkMemoryMeshBody's vtable (0x1691610) returns
 * its transform set's matricesNames. */
const hkStringPtr *hkMemoryMeshBody::FUN_00023140() const /* derived name */
{
    return transformSet->matricesNames.data;
}
