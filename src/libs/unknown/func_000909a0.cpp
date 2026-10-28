/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 0 of its vtable (0x16a3460), the complete destructor, and slot 1
 * (0x90930), the deleting one: the members destroy themselves. */
BufferAllocator::~BufferAllocator() {}
