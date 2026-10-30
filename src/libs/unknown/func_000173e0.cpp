/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived names: slot 4 of Class168e810's second-base vtable (0x168e888):
 * the this-adjusting thunk of primary slot 7 (FUN_000172c0, too large to
 * inline into it), back from the interface at +0x10 to the object. Written
 * as a call because the overrider's body is not written yet; the object is
 * never null here, so the conversion goes through a reference. */
void FUN_000173e0(Interface168e888 *self, TaskNode000172c0 *node,
                  TaskNode000172c0 *successor) /* derived name */
{
    FUN_000172c0(&static_cast<Class168e810 &>(*self), node, successor);
}
