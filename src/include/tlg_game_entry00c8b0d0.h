/* src/include/tlg_game_entry00c8b0d0.h: a 0xb0-byte record three holders
 * keep in arrays (game region; docs/TARGETS.md). Every name here is
 * derived. */
#ifndef TLG_GAME_ENTRY00C8B0D0_H
#define TLG_GAME_ENTRY00C8B0D0_H

#include "tlg_types.h"
#include "tlg_math.h"
#include "tlg_game_node.h"

/* derived names: the record FUN_00c8b0d0 appends to one of two sets of 64
 * (two aligned vectors stored, the float at +0x30 set to -1, the reference
 * at +0x98 emptied by compare-and-swap), FUN_00373200 puts back to empty in
 * an array of four (the float and the int after it to -1, the pointers at
 * +0x80 and +0xa0 cleared, the reference emptied) and FUN_00afd570 destroys
 * in a block from operator new[] (the reference dropped the plain way: the
 * member's destructor). The other fields are not traced. */
struct Entry00c8b0d0 { /* derived name */
    Float4A unknown0;  /* +0x0 */
    Float4A unknown10; /* +0x10 */
    u8 unknown20[0x10];
    float unknown30; /* +0x30 */
    int unknown34;   /* +0x34 */
    u8 unknown38[0x48];
    void *unknown80; /* +0x80 */
    u8 unknown88[0x10];
    AtomicRef0045c470<Node00503fb0> unknown98; /* +0x98 */
    void *unknowna0;                           /* +0xa0 */
    u8 unknowna8[0x8];
};

#endif
