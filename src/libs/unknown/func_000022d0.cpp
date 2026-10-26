/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 20 of TwoBaseAllocator's vtable (0x168c640) returns
 * the bytes handed out below it since the base count. It overrides slot 8
 * of the second base, so its this-adjusting thunk (0x2300, the body
 * inlined: the fields 8 bytes nearer) is emitted with it. The base count
 * is read before the allocator below is asked, as the bytes order it (slot
 * 18, 0x2230, reads it after the call). */
u64 TwoBaseAllocator::allocatedBytes() const /* derived name */
{
    if (!allocator38) {
        return 0;
    }
    const u64 base = baseBytes;
    return allocator38->allocatedBytes() - base;
}
