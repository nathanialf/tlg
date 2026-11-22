/* src/include/tlg_game_object002c5780.h: an object holding two arrays of
 * pointers that FUN_002c5780 and FUN_002c6800 add to (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT002C5780_H
#define TLG_GAME_OBJECT002C5780_H

#include "tlg_game_array.h"

struct Entry002c5780; /* derived name: the elements of the array at +0x2f8, not traced */
struct Entry002c6800; /* derived name: the elements of the array at +0x310, not traced */

/* derived names: the arrays at +0x2f8 and +0x310 (block, count, capacity,
 * owner index each, 0x18 bytes apart); the rest is not traced.
 * FUN_002c4710 hands it the entries of its own arrays at +0x538 and +0x550
 * one by one (0x2c4f31, 0x2c4f71) */
struct Object002c5780 { /* derived name */
    /* adds an entry to the array at +0x2f8 unless it is null or held
     * already (FUN_002c5780, called at 0x2c4f31 and 0x2c4f71) */
    void addEntry(Entry002c5780 *entry); /* derived name */
    /* the same over the array at +0x310 (FUN_002c6800, called at
     * 0x29f541, 0x2c6dc4 and 0x2c7261) */
    void addEntry(Entry002c6800 *entry); /* derived name */

    u8 unknown0[0x2f8];
    Array05943280<Entry002c5780 *> entries2f8; /* +0x2f8 */
    Array05943280<Entry002c6800 *> entries310; /* +0x310 */
};

#endif
