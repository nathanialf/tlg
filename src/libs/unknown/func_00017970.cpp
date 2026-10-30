/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 11 of the primary vtable; it overrides slot 8 of the second base, so
 * its this-adjusting thunk (0x17a50, a jump: -0x10 to the object) is emitted
 * with it. */
void Class168e810::FUN_00017970(const Handle00016350 *const *handles,
                                int numHandles) /* derived name */
{
    TempArray<const Handle00016350 *> named;
    named.reserve(hkContainerTempAllocator::get(), numHandles);
    for (int i = 0; i < numHandles; i++) {
        if (handles[i]->value != -1) {
            named.pushBackUnchecked(handles[i]);
        }
    }
    FUN_00092fe0(this, named.data, named.size);
}
