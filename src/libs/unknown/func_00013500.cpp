/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 10 of hkLargeBlockAllocator's vtable (address point
 * 0x168e2a0) returns the usable size of a block: the size in its chunk
 * header, flags masked off, less the header. */
int hkLargeBlockAllocator::FUN_00013500(const void *pointer, int numBytes) const /* derived name */
{
    const LargeBlockChunk *chunk = static_cast<const LargeBlockChunk *>(pointer) - 1;
    return static_cast<int>(chunk->head & ~static_cast<u64>(3)) -
           static_cast<int>(sizeof(LargeBlockChunk));
}
