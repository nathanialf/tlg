/* src/include/tlg_game_readlock.h: the reader count FUN_01331c10 takes
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_READLOCK_H
#define TLG_GAME_READLOCK_H

/* derived names: a count of readers that a writer holds by storing 0x10000
 * in it (the node's destructor, `lock cmpxchg [rbx+0x30], 0x10000` at
 * 0xc555ba). FUN_01331c10 takes a reader's place in it (a compare-and-swap
 * loop: `mov; lock cmpxchg; cmove; cmp`) and is given the lock itself, so
 * the drop, an atomic decrement of the count, forms the count's address
 * apart from the address the call was given: the base's releases fold it
 * (`lock dec dword ptr [r14 + 0x30]` at 0x61bf88, after `lea rdi, [r14 +
 * 0x30]` for the call; round 569D: 758 such sites against 110 where the
 * drop reuses the call's address, Object016b85e0::findComponent's) */
struct ReadLock01331c10 { /* derived name */
    int count;
};

void FUN_01331c10(ReadLock01331c10 *lock); /* derived name: the lock taken as a reader */

#endif
