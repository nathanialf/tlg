/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: equal but for three references the gate cannot resolve yet:
// the vtable 0x168e5b0 has no row (a D14 ruling), and the free list's
// destructor (0x18770) and AllocatorBase's (the empty 0x8d60) have FUN_ rows.
FixedSizeAllocator::~FixedSizeAllocator() {}
