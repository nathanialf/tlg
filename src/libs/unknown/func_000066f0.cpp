/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkReferencedObjectLock's destructor (slot 0 of its vtable 0x168caf0; the
 * deleting destructor 0x6740 in slot 1): the critical section's mutex
 * destroyed and checked. */
// NONMATCHING: equal to 0x66f0 and, through the inline delete, 0x6740, but
// the vtable: its derived row names the class Object00006800
// (_ZTV14Object00006800) where the singleton string 0x14b2c9c names it
// hkReferencedObjectLock (a ruling for the supervisor).
hkReferencedObjectLock::~hkReferencedObjectLock() {}
