/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name (the interface slot's name, after TwoBaseAllocator's
 * overrider): the memory walk. Its this-adjusting thunk (0x12fb0) comes
 * with it, the body inline. */
int hkLargeBlockAllocator::FUN_00002f10(MemoryWalkCallback callback, void *param)
{
    top->head = topSize | 1;
    for (Page *page = pages.next; page != &pages; page = page->next) {
        Chunk *chunk = page->firstChunk;
        if (!chunk) {
            return 0;
        }
        Chunk *const footer = reinterpret_cast<Chunk *>(page->end) - 1;
        for (;;) {
            callback(chunk + 1, chunk->head & ~u64(3), (chunk->head & 2) != 0, 0, param);
            chunk = reinterpret_cast<Chunk *>(reinterpret_cast<char *>(chunk) +
                                              (chunk->head & ~u64(3)));
            if (chunk == footer) {
                break;
            }
            if (!chunk) {
                return 0;
            }
        }
    }
    return 0;
}
