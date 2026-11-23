/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_creation.h"
#include "tlg_game_name.h"
#include "tlg_sce_kernel.h"

/* derived names: the name table's buckets, one word each: the index of the
 * chain's first entry in the low 31 bits, bit 31 set while a thread holds
 * the bucket; the count of entries freed; the arena the table and the
 * strings it owns are kept in (64 MiB from the table), whose blocks
 * FUN_00d67820 gives back by their size */
extern int D_5949980[];
extern u64 D_5989988;
void FUN_00d67820(void *block, unsigned size); /* derived name */

/* derived name: a short wait for a lock another thread holds: a 100000 ns
 * timer on the thread's queue and a wait for its event, or, where the timer
 * cannot be armed, a sleep of one microsecond (Lock059458a4::lock's wait) */
static inline void waitForLock() /* derived name */
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

/* derived name: the bucket given back with its word set to the chain's
 * first index (the word exchanged until the exchange holds) */
static inline void unlockBucket(int *bucket, unsigned first) /* derived name */
{
    int word;
    do
        word = *bucket;
    while (compareAndSwap(bucket, word, first) != word);
}

/* derived names: frees the entry of a name whose last reference is gone
 * (Name::release): under its bucket's lock the entry's hold is dropped and,
 * with the last, its string (when the arena holds it) and the entry are
 * given back, the entry taken out of the bucket's chain and the count of
 * freed entries raised */
void FUN_00d66e30(unsigned index) /* derived name */
{
    NameTableEntry017ac870 &entry = D_17ac870[index];
    int *bucket = &D_5949980[entry.hash8 & 0xffff];
    unsigned first;
    for (;;) {
        int word = *bucket;
        first = word & 0x7fffffff;
        if (compareAndSwap(bucket, first, word | 0x80000000) == int(first))
            break;
        waitForLock();
    }
    if (__sync_fetch_and_sub(&entry.holds16, 1) == 1) {
        const unsigned next = entry.nextc;
        const char *arena = reinterpret_cast<const char *>(D_17ac870);
        if (entry.string0 >= arena && entry.string0 < arena + 0x4000000)
            FUN_00d67820(const_cast<char *>(entry.string0), entry.length14 + 1);
        FUN_00d67820(&entry, sizeof(entry));
        if (first == index) {
            unlockBucket(bucket, next);
        } else {
            unsigned i = first;
            while (D_17ac870[i].nextc != index)
                i = D_17ac870[i].nextc;
            D_17ac870[i].nextc = next;
            unlockBucket(bucket, first);
        }
        __sync_fetch_and_add(&D_5989988, 1);
    } else {
        unlockBucket(bucket, first);
    }
}
