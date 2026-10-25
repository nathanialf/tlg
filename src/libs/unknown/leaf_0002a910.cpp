/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 8 of hkMemoryMeshShape's vtable (0x1692540) returns
 * its name. */
const char *hkMemoryMeshShape::FUN_0002a910() const /* derived name */
{
    return name.cString();
}
