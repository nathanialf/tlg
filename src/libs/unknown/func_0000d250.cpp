/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 7 of the memory system's vtable (address point
 * 0x168d690) reads slot 5 of its allocator interface at +0x20 as an int,
 * and answers 0 without one. */
int FUN_0000d250(MemorySystem *self) /* derived name */
{
    if (self->extended20) {
        return self->extended20->unknownVirtual5();
    }
    return 0;
}
