/* src/include/tlg_game_counted004a2d20.h: the class of the objects the
 * append FUN_004a2d20 takes references to (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_COUNTED004A2D20_H
#define TLG_GAME_COUNTED004A2D20_H

#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: one of the root class's (the count at +0x8), with the
 * number FUN_00481a70 gives it at +0x3a0; not traced further. The array of
 * references to it has its append as a function of its own in the
 * executable, FUN_004a2d20 (leaf_004a2d20.cpp), called from 2 sites in
 * FUN_00481a70. */
struct Counted004a2d20 : Object016b9108 { /* derived name */
    u8 unknown24[0x37c];
    int number3a0; /* +0x3a0 */
};

typedef Array05943280<Ref00503fb0<Counted004a2d20>> Array004a2d20; /* derived name */

#endif
