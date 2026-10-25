/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: whether the buffer allocator's whole buffer could hold a
 * block of the given size (tlg_lib_unknown.h). */
bool BufferAllocator::FUN_00091090(int numBytes) const /* derived name */
{
    return static_cast<int>(bufferEnd - bufferStart) >= numBytes;
}
