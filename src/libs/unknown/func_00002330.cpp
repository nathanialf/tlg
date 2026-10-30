/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A value kept for every allocator of this kind (derived name): the one
 * write is slot 20's, under the lock. */
extern int D_16dc128;

/* derived name: slot 20 of TwoBaseAllocator's vtable (0x168c640, at 0x168c6e0): the
 * value stored under the lock. It overrides slot 9 of the second base
 * (the thunk 0x2400 is claimed from its own file, func_00002400.cpp). */
void TwoBaseAllocator::FUN_00002330(int value)
{
    criticalSection.enter();
    D_16dc128 = value;
    criticalSection.leave();
}
