/* src/include/tlg_game_counted00952820.h: the class of the objects the
 * append FUN_00952820 takes references to (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_COUNTED00952820_H
#define TLG_GAME_COUNTED00952820_H

#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: what the +0x28 of an owner points to: an int at +0x21c
 * (FUN_009520e0's object reads one at the same offset) */
struct Object009522e0_28 { /* derived name */
    u8 unknown0[0x21c];
    int unknown21c; /* +0x21c */
};

/* derived names: what the +0x38 of an object points to, as FUN_009522e0
 * reads it */
struct Owner009522e0 { /* derived name */
    u8 unknown0[0x28];
    Object009522e0_28 *unknown28; /* +0x28 */
    int unknown30;                /* +0x30 */
    u8 unknown34[4];
    u16 flags38; /* +0x38: bits 0 and 8 tested together */
};

/* derived names: one of the root class's (the count at +0x8), of the type
 * at 0x5945418, with a pointer at +0x38; not traced further. The array of
 * references to it has its append as a function of its own in the
 * executable, FUN_00952820 (leaf_00952820.cpp), called from 2 sites in
 * FUN_009522e0. */
struct Counted00952820 : Object016b9108 { /* derived name */
    u8 unknown24[0x14];
    Owner009522e0 *owner38; /* +0x38 */
};

typedef Array05943280<Ref00503fb0<Counted00952820>> Array00952820; /* derived name */

#endif
