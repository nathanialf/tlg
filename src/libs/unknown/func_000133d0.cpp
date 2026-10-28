/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: slot 2 of hkLargeBlockAllocator's second-base vtable
 * (0x168e360): the this-adjusting thunk of primary slot 13 (FUN_000131a0,
 * too large to inline into it), back from the interface at +8 to the
 * object. Written as a call because the overrider's body is not written
 * yet; the object is never null here, so the conversion goes through a
 * reference. */
void FUN_000133d0(AllocatorInterface *self) /* derived name */
{
    FUN_000131a0(&static_cast<hkLargeBlockAllocator &>(*self));
}
