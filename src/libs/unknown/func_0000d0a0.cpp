/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 14 of the memory system's vtable (address point
 * 0x168d690): collect the garbage of the allocator at +0x20, when there is
 * one. */
void FUN_0000d0a0(MemorySystem *self)
{
    if (self->extended20) {
        self->extended20->garbageCollect();
    }
}
