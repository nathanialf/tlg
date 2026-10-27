/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: the base ends the function with a one-byte nop after the
// call of __stack_chk_fail, as every library function whose code ends in that
// call does (docs/NOTES.md, Round 32); this ends at the call.
void *TwoBaseAllocator::blockAlloc(int numBytes)
{
    return FUN_00008d70(numBytes);
}
