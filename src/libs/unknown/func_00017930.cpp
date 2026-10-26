/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived name: slot 10 of Class168e810's vtable (address point
 * 0x168e810): runs FUN_00016350 with mode 0 on a handle that names
 * something. */
void FUN_00017930(Class168e810 *self, const Handle00016350 *handle) /* derived name */
{
    if (handle->value == -1) {
        return;
    }
    FUN_00016350(self, 0, handle);
}
