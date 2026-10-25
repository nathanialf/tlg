/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: slot 10 of LargeBlockAllocator's second-base vtable
 * (0x168e360): the this-adjusting thunk of primary slot 19 (FUN_00013060,
 * too large to inline into it), back from the interface at +8 to the
 * object. Written as a call because the overrider's body is not written
 * yet; the object is never null here, so the conversion goes through a
 * reference. */
int FUN_00013190(AllocatorInterface *self, void *pointer, int value) /* derived name */
{
    return FUN_00013060(&static_cast<LargeBlockAllocator &>(*self), pointer, value);
}
