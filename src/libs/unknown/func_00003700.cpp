/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: slot 10 of TwoBaseAllocator's second-base vtable
 * (0x168c708): the this-adjusting thunk of primary slot 21 (FUN_000035a0,
 * too large to inline into it), back from the interface at +8 to the
 * object. Written as a call because the overrider's body is not written
 * yet; the object is never null here, so the conversion goes through a
 * reference. */
int FUN_00003700(AllocatorInterface *self, void *pointer, int value) /* derived name */
{
    return FUN_000035a0(&static_cast<TwoBaseAllocator &>(*self), pointer, value);
}
