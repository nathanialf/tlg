/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 16 of TwoBaseAllocator's vtable (0x168c640) returns the
 * pointer at +0xb50 that slot 15 stores under the object's lock. It overrides
 * slot 5 of the second base, so its this-adjusting thunk (0x3590, the getter
 * inlined: +0xb48 from the second base) is emitted with it. */
void *TwoBaseAllocator::FUN_00003580() const /* derived name */
{
    return pointerB50;
}
