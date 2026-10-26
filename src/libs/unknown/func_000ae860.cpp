/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 16 of hkStorageSkinnedMeshShape's vtable (address point
 * 0x16a3b00) sorts the parts by bone set. */
void hkStorageSkinnedMeshShape::FUN_000ae860()
{
    if (parts.size > 1) {
        FUN_000ad970(parts.data, 0, parts.size - 1, FUN_000ad900);
    }
}
