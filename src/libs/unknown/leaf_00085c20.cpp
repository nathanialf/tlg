/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 8 of hkxBlobMeshShape's vtable (address point
 * 0x16a07a0) returns its name. */
const char *hkxBlobMeshShape::FUN_00085c20() const /* derived name */
{
    return name.cString();
}
