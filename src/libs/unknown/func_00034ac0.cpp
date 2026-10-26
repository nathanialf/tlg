/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 4 of hknpCompressedMeshShapeInternals::KeyMask's vtable
 * (address point 0x1692ac0): the shape's mesh tree applies the filter. */
bool hknpCompressedMeshShapeInternals::KeyMask::FUN_000381d0()
{
    return shape->data->meshTree.FUN_000a92c0(filter);
}
