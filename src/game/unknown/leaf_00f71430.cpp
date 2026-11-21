/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016bfba8.h"

/* derived name: the complete destructor: the object takes itself out of the
 * array it is entered in, clears the int at +0x234 and empties the reference at +0x250;
 * then the members are released, last first, and the base's destructor
 * FUN_00c1b7f0 runs as a tail call. FUN_00f71ba0, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. */
// NONMATCHING: the complete destructor (1889 bytes, as the base): the array's emptying in the loop reallocates
// through an owner looked up from the block's tag with a null default (`mov edi, 0; cmp eax, 0xa; jne`), where
// reallocateBlock() indexes the table directly. With the lookup written in reallocateBlock() the function is equal
// (464 instructions), but 143 claimed rows (the appends, clear() and constructors over counted references) lose the
// direct form. The deleting destructor is equal and claimed
Object016bfba8::~Object016bfba8()
{
    if (registry)
        registry->remove(this);
    if (active234 != 0) {
        if (object2b8)
            object2b8->release();
        object2b8 = 0;
        if (object2c0)
            object2c0->release();
        object2c0 = 0;
        parts4b0[0].FUN_013d6920();
        parts4b0[1].FUN_013d6920();
        if (object680) {
            delete object680;
            object680 = 0;
        }
        /* the array is emptied inside the loop, after each delete (the
         * base's clear sits in the loop body; the loop's end is the one
         * read before it). */
        for (Holder00f71430 *holder : array690) {
            delete holder;
            array690.clear();
        }
        active234 = 0;
    }
    held.clear();
}
