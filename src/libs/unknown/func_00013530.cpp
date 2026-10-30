/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* dlmalloc's tree bins: sizes from 256 bytes, two bins a power of two. */
enum { TREEBIN_SHIFT = 8, NTREEBINS = 32 };

/* The tree bin a size belongs to (dlmalloc's compute_tree_index). derived
 * name. */
static inline int treeIndex(u64 size)
{
    const u64 x = size >> TREEBIN_SHIFT;
    if (x == 0) {
        return 0;
    }
    if (x > 0xffff) {
        return NTREEBINS - 1;
    }
    u32 y = u32(x);
    u32 n = ((y - 0x100) >> 16) & 8;
    u32 k = (((y <<= n) - 0x1000) >> 16) & 4;
    n += k;
    n += k = (((y <<= k) - 0x4000) >> 16) & 2;
    k = 14 - n + ((y <<= k) >> 15);
    return int((k << 1) + ((size >> (k + (TREEBIN_SHIFT - 1))) & 1));
}

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
