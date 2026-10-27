/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the context goes back at the head of the free list; the tag
 * in the head's upper bits is kept, only a take advances it. */
void hknpWorldContextPool::FUN_0016ffe0(const Context *context)
{
    const int index = context->index;
    u32 oldHead, newHead;
    do {
        oldHead = freeHead;
        next[index] = oldHead & 0xf;
        newHead = (oldHead & ~0xfu) | index;
    } while (__sync_val_compare_and_swap(&freeHead, oldHead, newHead) != oldHead);
}
