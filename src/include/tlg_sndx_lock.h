/* src/include/tlg_sndx_lock.h: the sound runtime's API lock (game region,
 * the sndx runtime at 0xec18b0 to 0xf15220 and the sound classes over it;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_SNDX_LOCK_H
#define TLG_SNDX_LOCK_H

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
 * runtime is not running (the count negative), else 0. The value read and
 * the one written are volatile: the count is changed by every thread that
 * calls the API, and each pass keeps both in the frame (every site reads
 * them back from their slots, `mov [rbp-0xc], eax` and the reloads before
 * the exchange and after it). */
inline int sndxStepCallers(int step) /* derived name */
{
    /* volatile: the count other threads change, as read (see above) */
    volatile s32 current;
    /* volatile: the value to exchange it for (see above) */
    volatile s32 next;
    do {
        const s32 count = D_179efe0;
        current = count;
        if (count < 0)
            return -3;
        next = current + step;
    } while (sndxCompareAndSwap(&D_179efe0, current, next) != current);
    return 0;
}

inline int sndxEnter() /* derived name */
{
    return sndxStepCallers(1);
}

inline int sndxLeave() /* derived name */
{
    return sndxStepCallers(-1);
}

#endif
