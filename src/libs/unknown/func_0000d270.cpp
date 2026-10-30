/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 8 of the memory system's vtable (address point
 * 0x168d690) asks its buffer allocator at +0x100 whether a block of the
 * size would fit; a bool return keeps the call (cookbook 25). */
bool FUN_0000d270(hkMemorySystem *self, int numBytes) /* derived name */
{
    return self->bufferAllocator.FUN_00091090(numBytes);
}
