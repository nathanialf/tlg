/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 12 of hkStorageSkinnedMeshShape's vtable (0x16a3b00)
 * returns its name. */
const char *hkStorageSkinnedMeshShape::FUN_000aea20() const /* derived name */
{
    return name.cString();
}
