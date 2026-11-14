/* src/include/tlg_game_pair00777d30.h: a 64-bit value and a counted
 * reference another thread may replace, kept as a pair (game region;
 * docs/TARGETS.md). Every name here is derived. FUN_00777d30
 * (leaf_00777d30.cpp) copies one; FUN_00776990 and its three copies set one
 * from a handle. The first field's meaning is not traced. */
#ifndef TLG_GAME_PAIR00777D30_H
#define TLG_GAME_PAIR00777D30_H

#include "tlg_game_node.h"

struct Pair00777d30 {                         /* derived name */
    u64 unknown0;                             /* +0x0 */
    AtomicRef0045c470<Node00503fb0> unknown8; /* +0x8 */
};

void FUN_00777d30(Pair00777d30 *self, const Pair00777d30 *other); /* derived name */

#endif
