/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 20 of hkLargeBlockAllocator's vtable (0x168e2a0) returns
 * the bytes handed out, block headers excluded. It overrides slot 8 of the
 * second base, so its this-adjusting thunk (0x12e30, the getter inlined:
 * +0x1a0 from the second base) is emitted with it. */
u64 hkLargeBlockAllocator::allocatedBytes() const /* derived name */
{
    return totalPayloadBytes;
}
