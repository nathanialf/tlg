/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

BufferAllocator::BufferAllocator()
    : bufferStart(0), bufferEnd(0), currentEnd(0), numAllocations(0), peakUse(0), lock(0)
{
}
