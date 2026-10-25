/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 9 of hkxBlobMeshShape's vtable (address point
 * 0x16a07a0) sets its name. */
void hkxBlobMeshShape::FUN_00085c30(const char *newName) /* derived name */
{
    FUN_0000e620(&name, newName);
}
