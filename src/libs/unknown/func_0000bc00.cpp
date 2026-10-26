/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: free a payload FUN_0000bba0's aligned kind of allocation
 * returned: the header before it loses its owner and the whole block, from
 * its start the payload's offset back, goes back with the header's 16 bytes
 * added to the size. A null payload is nothing to free. */
void FUN_0000bc00(AllocatorBase &allocator, void *payload) /* derived name */
{
    if (payload) {
        ArenaBlockHeader *header = static_cast<ArenaBlockHeader *>(payload) - 1;
        header->owner = 0;
        allocator.blockFree(static_cast<char *>(payload) - header->alignmentOffset,
                            header->size + sizeof(ArenaBlockHeader));
    }
}
