/* src/include/tlg_game_counted00d47fc0.h: the class of the objects the
 * append FUN_00d47fc0 takes references to, and the holder of the array
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_COUNTED00D47FC0_H
#define TLG_GAME_COUNTED00D47FC0_H

#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object05945a38.h"

/* derived names: one of the root class's, made by FUN_00d47a90 as an
 * object of the type at 0x5948af8 under the empty name; it is given a name
 * at +0x28. Not traced further. The array of references to it has its
 * append as a function of its own in the executable, FUN_00d47fc0
 * (leaf_00d47fc0.cpp), called from 2 sites in FUN_00d47a90. */
struct Counted00d47fc0 : Object016b9108 { /* derived name */
    u8 unknown24[0x4];
    Name name28; /* +0x28 */
};

typedef Array05943280<Ref00503fb0<Counted00d47fc0>> Array00d47fc0; /* derived name */

/* derived names: the object that holds the array at +0x268; the rest of it
 * is not traced */
struct Holder00d47a90 { /* derived name */
    u8 unknown0[0x268];
    Array00d47fc0 objects268; /* +0x268 */
};

/* derived names: the object FUN_00d47a90 makes its object for, one of the
 * root class's with a flag byte at +0x24 */
struct Source00d47a90 : Object016b9108 { /* derived name */
    u8 flags24;                          /* +0x24: bit 7 set by FUN_00d47a90 */
};

/* derived name: the type of the object FUN_00d47a90 makes
 * (`mov rsi, [0x5948af8]` before FUN_00cbc5a0) */
extern Type00503fb0 *D_5948af8;

/* takes the made object into the holder; not traced */
void FUN_00d461b0(Counted00d47fc0 *object, Holder00d47a90 *holder); /* derived name */

#endif
