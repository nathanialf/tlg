/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The counts set from the mesh tree's primitives: a triangle counts one, a
 * quad two, a custom primitive one convex shape. */
void hknpCompressedMeshShape::FUN_0010be70()
{
    numTriangles = 0;
    numConvexShapes = 0;
    const hkcdStaticMeshTreeBase &tree = data->meshTree;
    for (int i = 0; i < tree.primitives.getSize(); i++) {
        switch (tree.primitives.data[i].getType()) {
        case hkcdStaticMeshTreeBase::Primitive::TRIANGLE:
            numTriangles++;
            break;
        case hkcdStaticMeshTreeBase::Primitive::QUAD:
            numTriangles += 2;
            break;
        case hkcdStaticMeshTreeBase::Primitive::CUSTOM:
            numConvexShapes++;
            break;
        default:
            break;
        }
    }
}
