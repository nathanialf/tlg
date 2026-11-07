/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkResult FreeList::FUN_00018fc0(MemorySnapshot00011280 &snapshot, u8 status, int sourceId)
{
    /* A free element is unused, unless the caller records the whole list
     * under another status than in use. */
    const u8 freeStatus = (status == MemorySnapshot00011280::STATUS_USED)
                              ? u8(MemorySnapshot00011280::STATUS_UNUSED)
                              : status;

    /* The free blocks' elements are all free. */
    for (FreeListBlock *block = freeBlocks; block != HK_NULL; block = block->next) {
        char *const end = block->elements + block->numElements * elementSize;
        for (char *element = block->elements; element < end; element += elementSize) {
            snapshot.FUN_00011280(sourceId, freeStatus, element, int(elementSize));
        }
    }

    if (activeBlocks == HK_NULL && freeHead == HK_NULL) {
        return HK_SUCCESS;
    }

    /* The blocks in use and the free elements sorted by address, the rest
     * of the current block freed first, so one walk of both tells each
     * element's status. */
    activeBlocks = FUN_000183c0(activeBlocks);
    Element *head = freeHead;
    for (char *element = top; element < blockEnd; element += elementSize) {
        reinterpret_cast<Element *>(element)->next = head;
        head = reinterpret_cast<Element *>(element);
    }
    freeHead = head;
    blockEnd = HK_NULL;
    top = HK_NULL;
    freeHead = static_cast<Element *>(FUN_00092040(freeHead));

    /* The free elements link through their first word. */
    Element *nextFree = freeHead;
    for (FreeListBlock *block = activeBlocks; block != HK_NULL; block = block->next) {
        char *const end = block->elements + block->numElements * elementSize;
        for (char *element = block->elements; element < end; element += elementSize) {
            if (element == static_cast<void *>(nextFree)) {
                snapshot.FUN_00011280(sourceId, freeStatus, element, int(elementSize));
                nextFree = nextFree->next;
            } else {
                snapshot.FUN_00011280(sourceId, status, element, int(elementSize));
            }
        }
    }
    return HK_SUCCESS;
}
