/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: slot 12 of the memory system's vtable (0x168d6f0) returns the
 * allocator its constructor stored at +0x18. The same body fills seven
 * slots of other vtables (0x1695bf8 onward, docs/NOTES.md, folded bodies). */
AllocatorBase *FUN_0000d2b0(const hkMemorySystem *self) /* derived name */
{
    return self->allocator18;
}
