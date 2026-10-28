/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkxBlob's destructor (slot 0 of its vtable): the bytes given back. */
hkxBlob::~hkxBlob() {}

/* hkxBlobMeshShape's destructor (slot 0 of its vtable), beside the blob's,
 * which it inlines: the name, then the blob's bytes. */
hkxBlobMeshShape::~hkxBlobMeshShape() {}
