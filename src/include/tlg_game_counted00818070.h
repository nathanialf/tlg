/* src/include/tlg_game_counted00818070.h: the class of the objects the
 * append FUN_00818070 takes references to (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_COUNTED00818070_H
#define TLG_GAME_COUNTED00818070_H

#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: one of the root class's (the count at +0x8), with a flag
 * byte at +0x24 whose bit 0 FUN_013bc9f0 and FUN_013b7160 test before they
 * append a reference to the object; not traced further. The array of
 * references to it has its append as a function of its own in the
 * executable, FUN_00818070 (leaf_00818070.cpp), called from 8 sites. */
struct Counted00818070 : Object016b9108 { /* derived name */
    u8 flags24;                           /* +0x24 */
};

typedef Array05943280<Ref00503fb0<Counted00818070>> Array00818070; /* derived name */

#endif
