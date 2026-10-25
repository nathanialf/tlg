/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"

/* derived name: slot 12 of Class168e810's vtable (0x168e810) hands the call
 * to the object at +0x18. It overrides slot 9 of the second base, so its
 * this-adjusting thunk (0x17270, the forward inlined: +8 from the second
 * base) is emitted with it. */
void Class168e810::FUN_00017260(void *pointer, int count) /* derived name */
{
    FUN_000158f0(object18, pointer, count);
}
