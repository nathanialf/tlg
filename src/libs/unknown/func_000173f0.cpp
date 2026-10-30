/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 8 of the primary vtable; it overrides slot 5 of the second base, so
 * its this-adjusting thunk (0x17530, a jump: -0x10 to the object) is emitted
 * with it. */
void Class168e810::FUN_000173f0(const TaskPair000173f0 *pairs, int numPairs) /* derived name */
{
    lock.enter();
    for (int i = 0; i < numPairs; i++) {
        TaskNode000172c0 *node = pairs[i].node;
        TaskNode000172c0 *successor = pairs[i].successor;
        const int counter = node->counter;
        if (counter != -1) {
            node->successors.pushBack(successor);
            successor->counter++;
        }
    }
    lock.leave();
}
