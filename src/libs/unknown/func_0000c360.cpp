/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slots 0 and 1 of its vtable (0xc360, and 0xc350 the deleting one, a jump
 * to it: the interface's delete frees nothing): the members destroying
 * themselves, the last built first, then the interface's destructor, a tail
 * jump to 0x6c80. */
hkFreeListMemorySystem::~hkFreeListMemorySystem() {}
