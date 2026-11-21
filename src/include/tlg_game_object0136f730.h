/* src/include/tlg_game_object0136f730.h: the object slots 6 and 9 of the
 * vtables at 0x16cbf68 and 0x16cbf30 are given (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT0136F730_H
#define TLG_GAME_OBJECT0136F730_H

#include "tlg_game_node.h"

/* derived names: four pairs of counted references another thread may
 * replace at +0x58 and +0x78 (FUN_0136f5a0 empties each pair by
 * compare-and-swap) and a pointer at +0x28 handed to FUN_008113a0 with each
 * pair; the types are not traced */
struct Object0136f730 /* derived name */
{
    u8 unknown0[0x28];
    void *unknown28; /* +0x28 */
    u8 unknown30[0x28];
    AtomicRef0045c470<Object016b9108> first58[4];  /* +0x58 */
    AtomicRef0045c470<Object016b9108> second78[4]; /* +0x78 */
};

void FUN_008113a0(void *target, void *first, void *second); /* derived name */

#endif
