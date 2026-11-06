/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkxMesh's destructor: the user channels' and the sections' references
 * released from the last, each array's storage freed (the members in
 * reverse order); the deleting destructor (0x8beb0) is emitted here with
 * it and frees through the class's delete. */
hkxMesh::~hkxMesh() {}
