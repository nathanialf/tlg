/* src/include/tlg_game_counted008e3850.h: the class of the objects the
 * append FUN_008e3850 takes references to, and the holder of the array
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_COUNTED008E3850_H
#define TLG_GAME_COUNTED008E3850_H

#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object05945a38.h"

/* derived names: one of the root class's, made by FUN_008e1200 as an
 * object of the type at 0x581f4d0 under the empty name; it carries the
 * name of the object it stands for at +0x24. Not traced further. The array
 * of references to it has its append as a function of its own in the
 * executable, FUN_008e3850 (leaf_008e3850.cpp), called from 2 sites in
 * FUN_008e1200. */
struct Counted008e3850 : Object016b9108 { /* derived name */
    Name name24;                          /* +0x24 */
};

typedef Array05943280<Ref00503fb0<Counted008e3850>> Array008e3850; /* derived name */

/* derived names: the object that holds the array at +0x1d0; the rest of it
 * is not traced */
struct Holder008e1200 { /* derived name */
    u8 unknown0[0x1d0];
    Array008e3850 objects1d0; /* +0x1d0 */
};

/* derived names: the object FUN_008e1200 is asked about: the object at
 * +0x98, of the root class, whose name the made object carries */
struct Source008e1200 { /* derived name */
    u8 unknown0[0x98];
    Object016b9108 *object98; /* +0x98 */
};

/* derived name: the type of the object FUN_008e1200 makes
 * (`mov rsi, [0x581f4d0]` before FUN_00cbc5a0) */
extern Type00503fb0 *D_581f4d0;

#endif
