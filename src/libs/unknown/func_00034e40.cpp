/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the cleanup callback of hknpCompressedMeshShapeTree's type
 * info (registered at 0x35163; the mesh tree instance's type info, at
 * 0x3575b, cites the same body): the tree destroyed in place, its data runs,
 * shared and packed vertices given back, then the base's destructor. */
void FUN_00034e40(void *object)
{
    static_cast<hknpCompressedMeshShapeTree *>(object)->~hknpCompressedMeshShapeTree();
}
