/* src/include/tlg_game_counted004b5ff0.h: the class of the objects the
 * append FUN_004b5ff0 takes references to, and the holder of the array
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_COUNTED004B5FF0_H
#define TLG_GAME_COUNTED004B5FF0_H

#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object05945a38.h"

/* derived names: the object FUN_004b5760 makes an object for, one of the
 * root class's whose first own virtual (slot 5) answers whether it takes
 * one */
struct Source004b5760 : Object016b9108 { /* derived name */
    virtual bool slot5();                /* derived name; not traced */
};

/* derived name: the type of the object FUN_004b5760 makes
 * (`mov rsi, [0x57d7ea8]` before FUN_00cbc5a0) */
extern Type00503fb0 *D_57d7ea8;

/* derived names: one of the root class's, made by FUN_004b5760 as an
 * object of the type at 0x57d7ea8 under the empty name (mode 1); it holds
 * the source at +0x50 and the source's answer at +0x87. Not traced
 * further. The array of references to it has its append as a function of
 * its own in the executable, FUN_004b5ff0 (leaf_004b5ff0.cpp), called from
 * 2 sites in FUN_004b5760. */
struct Counted004b5ff0 : Object016b9108 { /* derived name */
    u8 unknown24[0x2c];
    AtomicRef0045c470<Source004b5760> source50; /* +0x50 */
    u8 unknown58[0x2f];
    bool taken87; /* +0x87: the source's slot 5 */
};

typedef Array05943280<Ref00503fb0<Counted004b5ff0>> Array004b5ff0; /* derived name */

/* derived names: the object that holds the array at +0x28; the rest of it
 * is not traced */
struct Holder004b5760 { /* derived name */
    u8 unknown0[0x28];
    Array004b5ff0 objects28; /* +0x28 */
};

#endif
