/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived name: slot 10 of Class168e810's vtable (address point
 * 0x168e810): runs FUN_00016350 with mode 0 on a handle that names
 * something. It overrides slot 7 of the second base, so its this-adjusting
 * thunk (0x17950, the body inlined: -0x10 to the object) is emitted with
 * it. */
void Class168e810::FUN_00017930(const Handle00016350 *handle) /* derived name */
{
    if (handle->value == -1) {
        return;
    }
    FUN_00016350(this, 0, handle);
}
