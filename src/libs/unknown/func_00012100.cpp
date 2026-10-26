/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 5 of the single-block allocator's vtable (address
 * point 0x168e220) takes the block back; a free when nothing is out, or of
 * another size than what was handed out, stops on the breakpoint. */
void SingleBlockAllocator::FUN_00012100(void *pointer, int numBytes)
{
    if (top != start && int(top - start) == numBytes) {
        top = 0;
    } else {
        HK_BREAKPOINT(0);
    }
}
