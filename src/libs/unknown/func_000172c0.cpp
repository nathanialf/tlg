/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 7 of the primary vtable; it overrides slot 4 of the second base, so
 * its this-adjusting thunk (0x173e0, a jump: -0x10 to the object) is emitted
 * with it. */
void Class168e810::FUN_000172c0(TaskNode000172c0 *node,
                                TaskNode000172c0 *successor) /* derived name */
{
    lock.enter();
    if (node->counter != -1) {
        node->successors.pushBack(successor);
        successor->counter++;
    }
    lock.leave();
}
