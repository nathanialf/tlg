/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void FUN_000172c0(Class168e810 *self, TaskNode000172c0 *node,
                  TaskNode000172c0 *successor) /* derived name */
{
    self->lock.enter();
    if (node->counter != -1) {
        node->successors.pushBack(successor);
        successor->counter++;
    }
    self->lock.leave();
}
