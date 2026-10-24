/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 5 of hkMemoryMeshBody's vtable (0x1691638) returns
 * the body's shape. */
hkMeshShape *hkMemoryMeshBody::FUN_000230d0() const /* derived name */
{
    return shape;
}
