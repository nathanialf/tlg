/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived name: slot 10 of Class168e810's vtable (address point
 * 0x168e810): waits, with mode 0, for a node not yet done
 * (FUN_00016350). It overrides slot 7 of the second base, so its this-adjusting
 * thunk (0x17950, the body inlined: -0x10 to the object) is emitted with
 * it. */
void Class168e810::FUN_00017930(TaskNode000172c0 *node) /* derived name */
{
    if (node->counter == -1) {
        return;
    }
    FUN_00016350(this, 0, node);
}
