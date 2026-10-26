/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 9 of the memory system's vtable (address point
 * 0x168d690) asks its allocator interface at +0x20 (slot 6), and answers
 * true without one. */
bool FUN_0000d290(MemorySystem *self) /* derived name */
{
    if (self->extended20) {
        return self->extended20->unknownVirtual6();
    }
    return true;
}
