/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 15 of TwoBaseAllocator's vtable (0x168c640): the byte
 * limit stored under the lock. It overrides slot 4 of the second base (the
 * thunk 0x3570 is claimed from its own file, func_00003570.cpp: the one
 * emitted here returns the constant itself). */
int TwoBaseAllocator::FUN_000034a0(u64 limit)
{
    criticalSection.enter();
    limitB50 = limit;
    criticalSection.leave();
    return 0;
}
