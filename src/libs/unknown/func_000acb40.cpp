/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The splice of the mesh material's textures (0xacb40), out of line: the
 * texture index's insertion (0xad043) splices one counted reference in. */
template void
hkArrayBase<hkRefPtr<hkMeshTexture>>::spliceInto(AllocatorBase &allocator, int index, int numToDel,
                                                 const hkRefPtr<hkMeshTexture> *elements,
                                                 int numToInsert);
