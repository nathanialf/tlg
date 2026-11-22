/* src/include/tlg_game_list0138c3b0.h: a list FUN_0138c3b0 empties (game
 * region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_LIST0138C3B0_H
#define TLG_GAME_LIST0138C3B0_H

#include "tlg_types.h"
#include "tlg_game_array.h"

/* derived names: a list FUN_0138c3b0 empties, its first entry at +0x8
 * (`mov r14, [rdi+8]; test r14, r14`) and a block-only array at +0x18,
 * whose block its destructor gives back (0x844873, the list at +0x98 of
 * Object016aeed0); not traced further */
struct List0138c3b0 { /* derived name */
    u8 unknown0[0x8];
    void *first8; /* +0x8 */
    u8 unknown10[0x8];
    Array05943280<void *> block18; /* +0x18: its elements not traced */
    u8 unknown30[0x8];
};

void FUN_0138c3b0(List0138c3b0 *list); /* derived name: not traced */

#endif
