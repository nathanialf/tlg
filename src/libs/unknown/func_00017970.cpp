/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 11 of the primary vtable; it overrides slot 8 of the second base, so
 * its this-adjusting thunk (0x17a50, a jump: -0x10 to the object) is emitted
 * with it. */
void Class168e810::FUN_00017970(TaskNode000172c0 *const *nodes, int numNodes) /* derived name */
{
    TempArray<TaskNode000172c0 *> notDone;
    notDone.reserve(hkContainerTempAllocator::get(), numNodes);
    for (int i = 0; i < numNodes; i++) {
        if (nodes[i]->counter != -1) {
            notDone.pushBackUnchecked(nodes[i]);
        }
    }
    FUN_00092fe0(this, notDone.data, notDone.size);
}
