/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 7 of hkMultipleVertexBuffer's vtable (address point
 * 0x1692000, and of hkMemoryMeshVertexBuffer's at 0x16921b0, whose format
 * sits at the same offset) copies the buffer's vertex format out. */
void hkMultipleVertexBuffer::FUN_00024be0(hkVertexFormat &formatOut) const /* derived name */
{
    FUN_000270b0(&formatOut, &vertexFormat);
}
