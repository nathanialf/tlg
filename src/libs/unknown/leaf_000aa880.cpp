/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 8 of hkSkinnedRefMeshShape's vtable (address point
 * 0x16a38c0) returns its name. */
const char *hkSkinnedRefMeshShape::FUN_000aa880() const /* derived name */
{
    return name.cString();
}
