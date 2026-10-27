/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 18 of TwoBaseAllocator's vtable (0x168c640): whether
 * the bytes handed out below it since the base count leave room for the
 * request under the limit at +0xb50, keeping the peak on the way; always,
 * without an allocator below. It overrides slot 6 of the second base, so
 * its this-adjusting thunk (0x2280, the body inlined: the fields 8 bytes
 * nearer) is emitted with it. */
bool TwoBaseAllocator::FUN_00002230(int numBytes)
{
    if (!allocator38) {
        return true;
    }
    const u64 allocated = allocator38->allocatedBytes() - baseBytes;
    peakBytes = hkMath::max2(allocated, peakBytes);
    return allocated < limitB50 - numBytes;
}
