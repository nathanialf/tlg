/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 3 of hknpCompressedMeshShapeInternals::KeyMask's vtable
 * (0x1692ad8): a key's bit in the filter set or cleared by the shape's mesh
 * tree, the key shifted down past the shape's own bits. */
void hknpCompressedMeshShapeInternals::KeyMask::FUN_000381b0(u32 key, bool enabled)
{
    const int numBits = shape->numShapeKeyBits;
    const u32 subKey = (key >> (32 - numBits)) & ((1 << numBits) - 1);
    shape->data->meshTree.FUN_000a9410(filter, subKey, enabled);
}
