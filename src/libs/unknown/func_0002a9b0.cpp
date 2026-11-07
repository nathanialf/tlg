/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The name given back, the index arrays' storage, each section destroyed
 * from the last (its bone map's indices, then its material's and its vertex
 * buffer's references) and the sections' storage; the vtable is emitted
 * here, with the deleting destructor (0x2a960) before this one. */
hkMemoryMeshShape::~hkMemoryMeshShape() {}
