/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: a context taken from the head of the free list; the tag in
 * the head's upper bits advances on every take, so a head read before
 * another thread's take and give back fails the exchange. */
hknpWorldContextPool::Context *hknpWorldContextPool::FUN_0016ff90()
{
    u32 oldHead, newHead, index;
    do {
        oldHead = freeHead;
        index = oldHead & 0xf;
        newHead = ((oldHead + 0x10) & ~0xfu) | next[index];
    } while (__sync_val_compare_and_swap(&freeHead, oldHead, newHead) != oldHead);
    next[index] = 0xf;
    return &contexts[index];
}
