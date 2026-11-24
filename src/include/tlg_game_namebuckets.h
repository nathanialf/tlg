/* src/include/tlg_game_namebuckets.h: the buckets of the name table at
 * 0x17ac870 (tlg_game_name.h), their lock, and the arena the table and the
 * strings it owns are kept in (game region; docs/TARGETS.md): what the
 * name's intern (FUN_013baad0) and its free (FUN_00d66e30) share. Every name
 * here is derived. */
#ifndef TLG_GAME_NAMEBUCKETS_H
#define TLG_GAME_NAMEBUCKETS_H

#include "tlg_game_creation.h"
#include "tlg_game_name.h"
#include "tlg_sce_kernel.h"
#include "tlg_types.h"

/* derived names: the name table's buckets, one word each (65536, picked by
 * the low 16 bits of the hash): the index of the chain's first entry in the
 * low 31 bits, bit 31 set while a thread holds the bucket; the count of
 * entries made (`lock inc qword` at 0x13bad0f) and of entries freed */
extern int D_5949980[];
extern u64 D_5989980;
extern u64 D_5989988;

/* derived names: a block of the arena the table and the strings it owns are
 * kept in (64 MiB from the table), of a size in bytes, and the same given
 * back by its size */
void *FUN_00d67350(size_t size);               /* derived name */
void FUN_00d67820(void *block, unsigned size); /* derived name */

/* derived name: a short wait for a lock another thread holds: a 100000 ns
 * timer on the thread's queue and a wait for its event, or, where the timer
 * cannot be armed, a sleep of one microsecond (Lock059458a4::lock's wait) */
inline void waitForLock() /* derived name */
{
    SceKernelTimespec time;
    time.tv_sec = 0;
    time.tv_nsec = 100000;
    SceKernelUseconds timeout = 1;
    SceKernelEqueue queue = D_16dc0a8;
    if (sceKernelAddHRTimerEvent(queue, 0, &time, 0) == 0) {
        SceKernelEvent event;
        int count = 0;
        sceKernelWaitEqueue(queue, &event, 1, &count, &timeout);
    } else {
        sceKernelUsleep(1);
    }
}

/* derived name: the bucket taken: its word exchanged from the chain's first
 * index to the same with bit 31 set, waiting while another thread holds it;
 * the first index it held is returned */
inline unsigned lockBucket(int *bucket) /* derived name */
{
    for (;;) {
        int word = *bucket;
        unsigned first = word & 0x7fffffff;
        if (compareAndSwap(bucket, first, word | 0x80000000) == int(first))
            return first;
        waitForLock();
    }
}

/* derived name: the bucket given back with its word set to the chain's
 * first index (the word exchanged until the exchange holds) */
inline void unlockBucket(int *bucket, unsigned first) /* derived name */
{
    int word;
    do
        word = *bucket;
    while (compareAndSwap(bucket, word, first) != word);
}

#endif
