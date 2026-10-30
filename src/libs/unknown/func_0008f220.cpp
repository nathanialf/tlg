/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 2 (0x8f220): under the lock, a block of the size asked for and its
 * header, rounded up to 16 bytes, drawn from the parent and put at the head
 * of the list; what is drawn and in use counted, the peak kept. */
void *BlockListAllocator::blockAlloc(int numBytes)
{
    lock.enter();
    int size = (numBytes + int(sizeof(Block)) + 15) & ~15;
    Block *block = static_cast<Block *>(parent->blockAlloc(size));
    block->numBytes = numBytes;
    block->size = size;
    block->next = blocks;
    blocks = block;
    void *payload = block + 1;
    statistics.allocated += size;
    statistics.inUse += numBytes;
    statistics.peakInUse = hkMath::max2(statistics.peakInUse, statistics.inUse);
    lock.leave();
    return payload;
}

// NONMATCHING: 43 of 95, same size: the base loads the list's link in the
// loop's header on the first pass too (`lea rdx, [rbp-0x30]`, then `mov rdx,
// [rcx]` from the copy of the head on the stack), where GVN's load PRE here
// forwards the stored head into the preheader and keeps the load in the
// latch; the registers of this and the block follow (docs/NOTES.md, Round
// 65A).
/* Slot 3 (0x8f330): under the lock, the block found on the list from a
 * copy of its head and unlinked, the counts lowered and the block given
 * back to the parent at the size it drew; a pointer not on the list is
 * left alone. */
void BlockListAllocator::blockFree(void *pointer, int numBytes)
{
    if (!pointer) {
        return;
    }
    lock.enter();
    Block *block = static_cast<Block *>(pointer) - 1;
    const int size = (numBytes + int(sizeof(Block)) + 15) & ~15;
    Block *head = blocks;
    Block **link = &head;
    while (Block *cur = *link) {
        if (cur == block) {
            *link = block->next;
            blocks = head;
            statistics.allocated -= size;
            statistics.inUse -= numBytes;
            parent->blockFree(block, block->size);
            break;
        }
        link = &cur->next;
    }
    lock.leave();
}
