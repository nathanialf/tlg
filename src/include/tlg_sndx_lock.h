/* src/include/tlg_sndx_lock.h: the sound runtime's API lock (game region,
 * the sndx runtime at 0xec18b0 to 0xf15220 and the sound classes over it;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_SNDX_LOCK_H
#define TLG_SNDX_LOCK_H

#include "tlg_sce_kernel.h"
#include "tlg_types.h"

/* derived names: the count of the API's callers at 0x179efe0, negative
 * while the runtime is not running: each call of the API takes a place in it
 * before it touches the runtime and gives it back after, both by an
 * exchange loop (229 sites read it: 0xebf110 and on). */
extern s32 D_179efe0;

/* the old value of *value, `replacement` stored in it when that was
 * `expected` (`lock cmpxchg; cmove`) */
inline s32 sndxCompareAndSwap(s32 *value, s32 expected, s32 replacement) /* derived name */
{
    __atomic_compare_exchange_n(value, &expected, replacement, false, __ATOMIC_SEQ_CST,
                                __ATOMIC_SEQ_CST);
    return expected;
}

/* one place more (`step` 1) or one less (-1) in the count, -3 when the
 * runtime is not running (the count negative), else 0. `current` and `next`
 * are the API function's own: the value read and the one written, volatile
 * because the count is changed by every thread that calls the API, and each
 * pass keeps both in the frame (every site reads them back from their slots,
 * `mov [rbp-0xc], eax` and the reloads before the exchange and after it).
 * One pair serves a function's enter and its leave: both use the same two
 * slots, which no other local of the function shares (0xed812b and 0xed8236
 * at -0x3c; 0xed79b6 and 0xed7b06 at -0x44 where the player's release and
 * the spin count share -0x34). */
inline int sndxStepCallers(volatile s32 &current, volatile s32 &next, int step) /* derived name */
{
    do {
        const s32 count = D_179efe0;
        current = count;
        if (count < 0)
            return -3;
        next = current + step;
    } while (sndxCompareAndSwap(&D_179efe0, current, next) != current);
    return 0;
}

inline int sndxEnter(volatile s32 &current, volatile s32 &next) /* derived name */
{
    return sndxStepCallers(current, next, 1);
}

inline int sndxLeave(volatile s32 &current, volatile s32 &next) /* derived name */
{
    return sndxStepCallers(current, next, -1);
}

/* derived name: the wait after a failed try of a lock, the longer the more
 * tries (`count`) have failed */
inline void sndxBackOff(u32 count)
{
    if (count > 128)
        sceKernelUsleep(1000);
    else if (count > 64)
        sceKernelUsleep(500);
    else if (count > 32)
        sceKernelUsleep(199);
    else if (count > 16)
        sceKernelUsleep(99);
}

/* derived names: a lock word, taken by exchanging 0 for 1; each failed try
 * backs off. The count of tries is volatile: the program waits on it, and
 * every site keeps it in the frame and reads it once a pass (0xed7a0b,
 * 0xebe16b, 0xefaf26) */
inline void sndxSpinLock(s32 *lock)
{
    /* volatile: the count of tries, as read (see above) */
    volatile u32 tries = 0;
    while (sndxCompareAndSwap(lock, 0, 1) != 0) {
        sndxBackOff(tries);
        ++tries;
    }
}

/* the lock word given back: 1 exchanged for 0 */
inline void sndxSpinUnlock(s32 *lock)
{
    while (sndxCompareAndSwap(lock, 1, 0) != 1) {}
}

/* derived names: a count of readers, -1 while a writer holds it: one reader
 * more once no writer holds it (backing off as sndxSpinLock while one does),
 * one less after. The values read and written and the count of tries are
 * volatile as in sndxStepCallers and sndxSpinLock (0xefaf33, 0xefaff0) */
inline void sndxReadLock(s32 *readers)
{
    /* volatile: the count other threads change, as read (see above) */
    volatile s32 current;
    /* volatile: the value to exchange it for (see above) */
    volatile s32 next;
    /* volatile: the count of tries (see above) */
    volatile u32 tries = 0;
    for (;;) {
        const s32 count = *readers;
        current = count;
        if (count == -1) {
            sndxBackOff(tries);
            ++tries;
            continue;
        }
        next = current + 1;
        if (sndxCompareAndSwap(readers, current, next) == current)
            break;
    }
}

inline void sndxReadUnlock(s32 *readers)
{
    /* volatile: the count other threads change, as read (see above) */
    volatile s32 current;
    /* volatile: the value to exchange it for (see above) */
    volatile s32 next;
    do {
        current = *readers;
        next = current - 1;
    } while (sndxCompareAndSwap(readers, current, next) != current);
}

#endif
