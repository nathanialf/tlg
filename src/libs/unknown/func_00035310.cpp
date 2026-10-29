/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hknpExternMeshShapeData's destructor: the build context deleted, then
 * the simd tree and the AABB tree's nodes. Its vtable comes with it, and
 * the deleting destructor (0x353c0). */
hknpExternMeshShapeData::~hknpExternMeshShapeData()
{
    delete buildContext;
}
