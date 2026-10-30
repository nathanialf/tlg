/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the thread's block quit (0x9a80, 0x9ad0): the buffer it
 * owns given back to the router's heap at +0x60 at its capacity, the block
 * cleared and freed there too, and the thread's pointer to it reset. The
 * block is the one the thread-local pointer names, read here again. */
void FUN_0000ead0(ThreadBuffer *)
{
    ThreadBuffer *block = D_16dc078; /* derived name */
    char *start = block->start;      /* derived name */
    if (start && block->isBufferAllocatedOnTheHeap) {
        const int numBytes = static_cast<int>(block->capacity - start);
        D_16dc070->allocator60->FUN_00008d80(start, numBytes);
    }
    block->isBufferAllocatedOnTheHeap = false;
    block->capacityMinus16 = HK_NULL;
    block->capacity = HK_NULL;
    block->end = HK_NULL;
    block->start = HK_NULL;
    D_16dc070->allocator60->blockFree(block, sizeof(ThreadBuffer));
    D_16dc078 = HK_NULL;
}
