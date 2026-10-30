/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpCompressedMeshShapeTree::FUN_00104000(hkGeometry *geometry, MeshTreeQuery00104000 *query,
                                               bool keepGeometry, bool weldVertices,
                                               int argument6) const
{
    if (!keepGeometry) {
        geometry->FUN_00093c70();
    }
    geometry->triangles.reserve(hkContainerHeapAllocator::get(),
                                geometry->triangles.getSize() + numPrimitiveKeys);
    geometry->vertices.reserve(hkContainerHeapAllocator::get(),
                               geometry->vertices.getSize() + numPrimitiveKeys * 3);
    for (int i = 0; i < sections.getSize(); i++) {
        FUN_00104110(i, geometry, query, 1, 0, argument6);
    }
    if (weldVertices) {
        FUN_001891e0(geometry, 0.0f);
    }
}
