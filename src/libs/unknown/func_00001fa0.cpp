/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: slots 0 and 1 of TwoBaseAllocator's second-base vtable
 * (0x168c708): the this-adjusting thunk of its complete destructor (the
 * deleting destructor's thunk is the same body, its operator delete being
 * empty), back from the interface at +8 to the object. Written as a call
 * because the destructor has no name yet; the object is never null here, so
 * the conversion goes through a reference. */
void FUN_00001fa0(AllocatorInterface *self) /* derived name */
{
    FUN_00001fb0(&static_cast<TwoBaseAllocator &>(*self));
}
