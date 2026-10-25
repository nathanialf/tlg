/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived names: slot 0 of Class168e810's second-base vtable (0x168e888):
 * the this-adjusting thunk of the complete destructor (FUN_00016f90, too large to
 * inline into it), back from the interface at +0x10 to the object. Written
 * as a call because the overrider's body is not written yet; the object is
 * never null here, so the conversion goes through a reference. */
void FUN_000170c0(Interface168e888 *self) /* derived name */
{
    FUN_00016f90(&static_cast<Class168e810 &>(*self));
}
