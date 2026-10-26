/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 6 of the memory system's vtable (address point
 * 0x168d690) hands its int to slot 4 of its allocator interface at +0x20,
 * widened to 64 bits, and answers 0 without one. */
int FUN_0000d230(MemorySystem *self, int value) /* derived name */
{
    if (self->extended20) {
        return self->extended20->unknownVirtual4(value);
    }
    return 0;
}
