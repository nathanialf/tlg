/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 15 of hkMemoryMeshVertexBuffer's vtable (address point 0x16921b0)
 * clears its locked flag. */
void hkMemoryMeshVertexBuffer::FUN_00027b10() /* derived name */
{
    locked = false;
}
