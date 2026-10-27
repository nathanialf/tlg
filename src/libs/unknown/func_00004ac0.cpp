/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The system heap allocator's destructor (slots 0 and 1 of its vtable
 * 0x168c9f0): nothing of its own to destroy, so it runs AllocatorBase's
 * out-of-line destructor. The linker folded the same body for five other
 * allocators' slot 0 (vtables 0x168d440, 0x168d4c0, 0x168d540, 0x168da10,
 * 0x168e220; also slot 1 of the last two), which cite it by address; it is
 * named for the class whose members sit beside it (D15). */
hkMallocAllocator::~hkMallocAllocator() {}
