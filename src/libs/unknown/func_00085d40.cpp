/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkxBlobMeshShape's finish constructor: the mesh shape and the blob need
 * only their vtables; the name finishes. */
hkxBlobMeshShape::hkxBlobMeshShape(hkFinishLoadedObjectFlag flag)
    : hkMeshShape(flag), blob(flag), name(flag)
{
}
