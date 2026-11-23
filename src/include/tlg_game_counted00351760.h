/* src/include/tlg_game_counted00351760.h: the class of the objects the
 * append FUN_00351760 takes references to, and the graph that holds them
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_COUNTED00351760_H
#define TLG_GAME_COUNTED00351760_H

#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object05945a38.h"

/* derived names: one of the root class's, an edge of the graph below
 * (named "<graph>_Edge_<n>" by FUN_008239d0). Not traced further. The
 * array of references to it has its append as a function of its own in
 * the executable, FUN_00351760 (leaf_00351760.cpp), called from 5 sites in
 * FUN_003496c0, FUN_00823580 and FUN_008239d0. */
struct Counted00351760 : Object016b9108 { /* derived name */
};

typedef Array05943280<Ref00503fb0<Counted00351760>> Array00351760; /* derived name */

/* derived names: the graph, of the root class: the object at +0x38 its
 * edges are handed to (FUN_00c55dd0) and its edges at +0x270, whose count
 * numbers the next one's name; the rest is not traced */
struct Graph008239d0 : Object016b9108 { /* derived name */
    u8 unknown24[0x14];
    Object016b9108 *unknown38; /* +0x38 */
    u8 unknown40[0x230];
    Array00351760 edges270; /* +0x270 */
};

/* not traced */
void FUN_00c55dd0(Counted00351760 *object, Object016b9108 *owner, int flags); /* derived name */

#endif
