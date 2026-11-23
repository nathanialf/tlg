/* src/include/tlg_game_object013bb780.h: the two global arrays of counted
 * references with their locks at 0x5989e88 and 0x5989ea0, FUN_00d701d0's
 * unit (func_00d701d0.cpp), whose complete destructor is FUN_013bb780
 * (leaf_013bb780.cpp) (game region; docs/TARGETS.md). Every name here is
 * derived. */
#ifndef TLG_GAME_OBJECT013BB780_H
#define TLG_GAME_OBJECT013BB780_H

#include "tlg_game_creation.h"
#include "tlg_game_object0134f620.h"

/* derived name: the array of counted references (tlg_game_object0134f620.h)
 * as its base, its lock (tlg_game_creation.h) in the array's tail padding,
 * as tlg_game_array01343a80.h's: the initializer clears the block, the count and the capacity in one 16-byte
 * store, stores the owner's index at +0x10 and makes the lock at +0x14
 * free (0xd701f1 to 0xd70348). The destructor's own body is empty, so the
 * array's destructor, 0x134f620, runs as a tail call. */
struct Object013bb780 : Object0134f620 /* derived name */
{
    ~Object013bb780();
    Lock059458a4 lock; /* +0x14 */
};

#endif
