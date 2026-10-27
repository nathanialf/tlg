/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: an aligned block: alignment and 16 bytes more than asked
 * for from the allocator's slot 2, the payload the first multiple of the
 * alignment past the 16-byte header, which records the allocator, the size
 * asked for plus the alignment, and the payload's offset into the block
 * (FUN_0000bc00 frees it). */
void *FUN_0000bba0(AllocatorBase &allocator, int numBytes, int alignment) /* derived name */
{
    char *unaligned = static_cast<char *>(allocator.blockAlloc(alignment + numBytes + 16));
    char *aligned = reinterpret_cast<char *>(
        (reinterpret_cast<hkUlong>(unaligned + 16) + (alignment - 1)) & ~(alignment - 1));
    ArenaBlockHeader *header = reinterpret_cast<ArenaBlockHeader *>(aligned) - 1;
    header->owner = &allocator;
    header->size = alignment + numBytes;
    header->alignmentOffset = int(aligned - unaligned);
    return aligned;
}
