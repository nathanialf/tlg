/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: hknpCompressedMeshShape's bounds in its own space, the domain
 * of its data's mesh tree (called by slot 7 of its vtable, 0x158840). */
const hkAabb *hknpCompressedMeshShape::FUN_0010bf40() const /* derived name */
{
    return &data->meshTree.domain;
}
