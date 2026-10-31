/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The class's key function: its vtable is emitted here, the deleting
 * destructor (0x158680, slot 1) before the destructor (0x1586d0, slot 0).
 * The data's reference released first, then the bit fields given back,
 * the composite shape's edge map and the shape's destructor (0x6fb50). */
hknpCompressedMeshShape::~hknpCompressedMeshShape()
{
    if (data) {
        data->removeReference();
        data = HK_NULL;
    }
}
