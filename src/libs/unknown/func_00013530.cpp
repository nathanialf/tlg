/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkLargeBlockAllocator::getMemoryStatistics(MemoryStatistics &statistics) const
{
    s64 total = 0;
    for (const Page *page = pages.next; page != &pages; page = page->next) {
        /* The size summed signed here (`movsxd`), where the page walk
         * extends it unsigned (0x130d5). */
        total += int(page->size);
    }
    statistics.allocated = total;
    statistics.inUse = totalPayloadBytes;
    statistics.available = total - totalPayloadBytes;

    u64 largest = topSize;
    const int topIndex = treeIndex(largest);
    for (int i = NTREEBINS - 1; i >= topIndex; i--) {
        const TreeChunk *chunk = treebins[i];
        if (chunk) {
            while (chunk) {
                const u64 size = chunk->head & ~u64(IN_USE_BITS);
                if (size > largest) {
                    largest = size;
                }
                chunk = chunk->child[1] ? chunk->child[1] : chunk->child[0];
            }
            break;
        }
    }
    statistics.largestBlock = largest;
    statistics.totalAvailable = 0;
}
