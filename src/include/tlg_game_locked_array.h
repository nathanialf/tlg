/* src/include/tlg_game_locked_array.h: an array with its own spin lock
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_LOCKED_ARRAY_H
#define TLG_GAME_LOCKED_ARRAY_H

#include "tlg_game_array.h"
#include "tlg_game_creation.h"

/* derived names: an array with a lock of its own, the word right after the
 * array's fields (the array at +0x10 of its holder and the lock at +0x24 in
 * FUN_0081a930, +0x28 and +0x3c in FUN_009f5a00, +0x38 and +0x4c in
 * FUN_01331d20: the lock lies in the array's last eight bytes, so it is a
 * member of a class over the array). The lock is the creation lock's class:
 * the same wait (the 100000 ns timer, the event queue, the microsecond's
 * sleep). */
template <class T> class LockedArray0081a930 : public Array05943280<T> /* derived name */
{
  public:
    Lock059458a4 lock; /* +0x14 */
};

#endif
