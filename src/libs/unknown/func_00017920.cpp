/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived names: runs FUN_00016350 on the object with the given mode and no
 * node to wait for; its sibling FUN_00017930 runs it with mode 0 for a node
 * not yet done. Called by the callback FUN_00007730 and from the
 * game region (0xea2e62). */
void FUN_00017920(Class168e810 *self, int mode) /* derived name */
{
    FUN_00016350(self, mode, 0);
}
