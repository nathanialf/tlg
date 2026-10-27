/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: size + 16 bytes from the allocator's slot 2, a 16-byte
 * header (owner, size) written and the payload returned. */
void *FUN_0000bc30(AllocatorBase &allocator, int size) /* derived name */
{
    ArenaBlockHeader *header = static_cast<ArenaBlockHeader *>(allocator.blockAlloc(size + 0x10));
    header->owner = &allocator;
    header->size = size;
    return header + 1;
}
