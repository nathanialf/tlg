/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 5 of hknpCompressedMeshShapeInternals::KeyMask's vtable
 * (0x1692ae8): whether a key passes the filter, asked of the shape's mesh
 * tree with the key shifted down past the shape's own bits. */
bool hknpCompressedMeshShapeInternals::KeyMask::FUN_000381f0(u32 key) const
{
    const int numBits = shape->numShapeKeyBits;
    const u32 subKey = (key >> (32 - numBits)) & ((1 << numBits) - 1);
    return shape->data->meshTree.FUN_000a9550(filter, subKey);
}
