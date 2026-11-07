/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name (the interface slot's name, after TwoBaseAllocator's
 * overrider): the garbage collection. */
void hkLargeBlockAllocator::FUN_00003140()
{
    top->head = topSize | PREVIOUS_IN_USE;
    reinterpret_cast<Chunk *>(reinterpret_cast<char *>(top) + topSize)->prevFoot = topSize;
    for (Page *page = pages.next; page != &pages;) {
        Chunk *chunk = page->firstChunk;
        if (!(chunk->head & IN_USE) &&
            reinterpret_cast<Chunk *>(reinterpret_cast<char *>(chunk) + (chunk->head & ~u64(3))) ==
                reinterpret_cast<Chunk *>(page->end) - 1) {
            Page *const next = page->next;
            page->prev->next = page->next;
            page->next->prev = page->prev;
            if (chunk == top) {
                top = reinterpret_cast<Chunk *>(&emptyTop);
                topSize = 0;
            } else {
                FUN_00012550(static_cast<TreeChunk *>(chunk));
            }
            server->FUN_00008d80(page, page->size);
            page = next;
        } else {
            page = page->next;
        }
    }

    if (pages.next == &pages) {
        top = reinterpret_cast<Chunk *>(&emptyTop);
        topSize = 0;
        return;
    }

    if (blockAllocator.start) {
        Page *const page = pages.next;
        if (topSize < 0x8000 || blockAllocator.start != reinterpret_cast<char *>(page)) {
            return;
        }
        const s64 newSize =
            reinterpret_cast<char *>(top) + 0x140 - reinterpret_cast<char *>(page->firstChunk);
        if (newSize < 0) {
            return;
        }
        char *const newTop = blockAllocator.start + newSize;
        if (newTop > blockAllocator.end) {
            return;
        }
        blockAllocator.top = newTop;
        const u64 footerHead =
            reinterpret_cast<Chunk *>(reinterpret_cast<char *>(top) + topSize)->head;
        const s64 change = int((int(newSize) - int(page->size)) & ~31);
        topSize += change;
        page->size = u32(newSize);
        page->end += change;
        reinterpret_cast<Chunk *>(reinterpret_cast<char *>(top) + topSize)->head =
            ((footerHead & ~u64(3)) - change) | IN_USE;
        return;
    }

    if (top != reinterpret_cast<Chunk *>(&emptyTop)) {
        FUN_00012410(static_cast<TreeChunk *>(top), topSize);
        top = reinterpret_cast<Chunk *>(&emptyTop);
        topSize = 0;
    }
    Chunk *largest = HK_NULL;
    for (Page *page = pages.next; page != &pages; page = page->next) {
        Chunk *const footer = reinterpret_cast<Chunk *>(page->end) - 1;
        if (footer->head & PREVIOUS_IN_USE) {
            continue;
        }
        Chunk *const last =
            reinterpret_cast<Chunk *>(reinterpret_cast<char *>(footer) - footer->prevFoot);
        if (!largest || (last->head & ~u64(3)) > (largest->head & ~u64(3))) {
            largest = last;
        }
    }
    if (largest) {
        FUN_00012550(static_cast<TreeChunk *>(largest));
        top = largest;
        topSize = largest->head & ~u64(3);
    } else {
        top = reinterpret_cast<Chunk *>(&emptyTop);
        topSize = 0;
    }
}
