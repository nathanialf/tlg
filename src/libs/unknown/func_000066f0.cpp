/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkReferencedObjectLock's destructor (slot 0 of its vtable 0x168caf0; the
 * deleting destructor 0x6740 in slot 1): the critical section's mutex
 * destroyed and checked. */
hkReferencedObjectLock::~hkReferencedObjectLock() {}
