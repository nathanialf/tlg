/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hknpShapeKeyMask *hknpCompressedMeshShape::FUN_00117200() const /* derived name */
{
    hknpCompressedMeshShapeInternals::KeyMask *mask = new hknpCompressedMeshShapeInternals::KeyMask;
    mask->shape = this;
    data->meshTree.FUN_000a9150(mask->filter);
    return mask;
}
