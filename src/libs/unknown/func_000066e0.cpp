/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkReferencedObject's destructor: nothing to release. Its deleting variant
 * (slot 1 of the vtable 0x168cb60, FUN_000066e0) frees the object through
 * the class allocator. */
hkReferencedObject::~hkReferencedObject() {}
