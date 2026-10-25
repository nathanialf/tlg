/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 6 of hkMemoryMeshVertexBuffer's vtable (address point
 * 0x16921b0) tells whether the buffer is sharable. */
bool hkMemoryMeshVertexBuffer::FUN_00027280() const /* derived name */
{
    return isSharable;
}
