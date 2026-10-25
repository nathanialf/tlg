/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 13 of hkStorageSkinnedMeshShape's vtable (0x16a3b00)
 * sets its name. */
void hkStorageSkinnedMeshShape::FUN_000aea30(const char *newName) /* derived name */
{
    FUN_0000e620(&name, newName);
}
