/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The allocator's pages and chunks in a memory snapshot. Its this-adjusting
 * thunk (0x13190) comes with it, a jump to the body. */
int hkLargeBlockAllocator::addToSnapshot(void *snapshotOut, int parentId)
{
    MemorySnapshot00011280 &snapshot = *static_cast<MemorySnapshot00011280 *>(snapshotOut);
    const int id = snapshot.FUN_00011170("hkLargeBlockAllocator", parentId);
    for (Page *page = pages.next; page != &pages; page = page->next) {
        snapshot.FUN_00011280(parentId, MemorySnapshot00011280::STATUS_USED, page, page->size);
        Chunk *chunk = page->firstChunk;
        Chunk *const footer = reinterpret_cast<Chunk *>(page->end) - 1;
        const char *const pageEnd = reinterpret_cast<const char *>(page) + page->size;
        snapshot.FUN_00011280(
            id, MemorySnapshot00011280::STATUS_OVERHEAD, page,
            int(reinterpret_cast<char *>(chunk) - reinterpret_cast<char *>(page)));
        while (chunk != footer) {
            snapshot.FUN_00011280(id, MemorySnapshot00011280::STATUS_OVERHEAD, chunk,
                                  sizeof(Chunk));
            const u64 head = chunk->head;
            snapshot.FUN_00011280(id,
                                  (head & 2) ? MemorySnapshot00011280::STATUS_USED
                                             : MemorySnapshot00011280::STATUS_UNUSED,
                                  chunk + 1, int(head - sizeof(Chunk)) & ~3);
            chunk = reinterpret_cast<Chunk *>(reinterpret_cast<char *>(chunk) +
                                              (chunk->head & ~u64(3)));
        }
        snapshot.FUN_00011280(id, MemorySnapshot00011280::STATUS_OVERHEAD, footer,
                              int(pageEnd - reinterpret_cast<char *>(footer)));
    }
    return id;
}
