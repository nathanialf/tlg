/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 11 of the buffer allocator's vtable (address point
 * 0x16a3470) resets the peak use to the bytes in use now. */
void BufferAllocator::FUN_000910d0() /* derived name */
{
    peakUse = currentEnd - bufferStart;
}
