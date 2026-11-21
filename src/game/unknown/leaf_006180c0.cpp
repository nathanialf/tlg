/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016c77b8.h"

/* derived name: the complete destructor: the pool given up, then the
 * pool's reference released and the base's destructor inlined (its vptr
 * store, then its two names). FUN_006182d0, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable.
 * NONMATCHING: shutdown() stays a call in the complete destructor and the
 * deleting one inlines that body (round 407A's 0xa83a60 class); the base
 * has shutdown() inlined and the deleting destructor calling 0x6180c0.
 * 0x8ee8f0's holder (a name between the pool and its reference) gets the
 * base's form from the same source. */
Object016c77b8::~Object016c77b8()
{
    pool.shutdown();
}
