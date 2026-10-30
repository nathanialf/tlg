/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 13 of the memory system's vtable (address point
 * 0x168d690): when each thread has its own allocator (flags bit 2), the
 * router's temporary allocator is that thread allocator, and its slot 13
 * runs. */
void FUN_0000d080(hkFreeListMemorySystem *self, hkMemoryRouter &router)
{
    if (self->flags & 4) {
        static_cast<ThreadMemory *>(router.temp58)->FUN_00014690();
    }
}
