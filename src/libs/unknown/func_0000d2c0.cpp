/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 20 of the memory system's vtable (address point
 * 0x168d690): forwards its argument to slot 9 of the allocator interface
 * at +0x20, when there is one. */
void FUN_0000d2c0(MemorySystem *self, int value) /* derived name */
{
    if (self->extended20) {
        self->extended20->unknownVirtual9(value);
    }
}
