/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slots 0 and 1 of its vtable (0xc360, and 0xc350 the deleting one, a jump
 * to it: the interface's delete frees nothing): the members destroying
 * themselves, the last built first, then the interface's destructor, a tail
 * jump to 0x6c80. */
// NONMATCHING: equal but for each thread record's slot 13 call (classified,
// docs/NOTES.md "Round 64B"): the base calls it through ThreadMemory's
// vtable (`mov r12, [vtable+0x78]; ... call r12`); 3.3 at -O2 emits the
// vtable available_externally (CGVTables.cpp shouldEmitVTableAtEndOfTranslationUnit),
// folds the slot and calls 0x14690 directly. Upstream r189852 (2013-09-03)
// removed that emission; with the vtables external the compile is the base's.
hkFreeListMemorySystem::~hkFreeListMemorySystem() {}
