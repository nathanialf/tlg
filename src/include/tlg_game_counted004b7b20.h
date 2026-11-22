/* src/include/tlg_game_counted004b7b20.h: the class of the objects the
 * append FUN_004b7b20 takes references to (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_COUNTED004B7B20_H
#define TLG_GAME_COUNTED004B7B20_H

#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: one of the root class's (the count at +0x8); not traced
 * further. The array of references to it has its append as a function of
 * its own in the executable, FUN_004b7b20 (leaf_004b7b20.cpp), called from
 * 2 sites in FUN_004b7170. */
struct Counted004b7b20 : Object016b9108 {}; /* derived name */

typedef Array05943280<Ref00503fb0<Counted004b7b20>> Array004b7b20; /* derived name */

#endif
