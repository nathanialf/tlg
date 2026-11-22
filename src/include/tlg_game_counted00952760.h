/* src/include/tlg_game_counted00952760.h: the class of the objects the
 * append FUN_00952760 takes references to (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_COUNTED00952760_H
#define TLG_GAME_COUNTED00952760_H

#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: one of the root class's (the count at +0x8), with a flag
 * byte at +0x24 whose bit 0 FUN_013b7530 and FUN_009521f0 test before they
 * append a reference to the object; not traced further. The array of
 * references to it has its append as a function of its own in the
 * executable, FUN_00952760 (leaf_00952760.cpp), called from 2 sites. */
struct Counted00952760 : Object016b9108 { /* derived name */
    u8 flags24;                           /* +0x24 */
};

typedef Array05943280<Ref00503fb0<Counted00952760>> Array00952760; /* derived name */

#endif
