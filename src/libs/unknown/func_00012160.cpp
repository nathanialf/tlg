/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkLargeBlockAllocator::hkLargeBlockAllocator(AllocatorBase *server)
    : listener(HK_NULL), server(server)
{
    treemap = 0;
    pointer20 = HK_NULL;
    memset(treebins, 0, sizeof(treebins));
    totalPayloadBytes = 0;
    totalBlockBytes = 0;
    emptyTop.head = 3;
    emptyTop.prevFoot = 0;
    top = reinterpret_cast<Chunk *>(&emptyTop);
    topSize = 0;
    pages.next = &pages;
    pages.prev = &pages;
}
