/* src/include/tlg_game_object009690d0.h: an object that fills the slots of
 * its target (game region; docs/TARGETS.md). derived names throughout. The
 * target at +0x10 holds four arrays of exchanged references (+0x1e8, +0x218,
 * +0x230 and +0x248, each with its count 8 bytes on) and, at +0x50, +0x58,
 * +0x78 and +0x60, the object each array's slots fall back to (FUN_009690d0,
 * FUN_00969330, FUN_009694b0, FUN_00969670: one function for each array,
 * all four called from 0x969fee on). Neither class is traced. */
#ifndef TLG_GAME_OBJECT009690D0_H
#define TLG_GAME_OBJECT009690D0_H

#include "tlg_types.h"
#include "tlg_game_node.h"

/* what a slot refers to */
class Base009690d0 : public Node00503fb0 /* derived name */
{
};

/* what goes into a slot: a class over the slot's (`cmp rsi, rbx` at
 * 0x969124: the pointer converted where it is exchanged and compared) */
class Value009690d0 : public Base009690d0 /* derived name */
{
};

struct Slots009690d0 {                      /* derived name */
    AtomicRef0045c470<Base009690d0> *slots; /* +0x0 */
    unsigned count;                         /* +0x8 */
    u8 unknownc[0xc];
};

struct Target009690d0 { /* derived name */
    u8 unknown0[0x50];
    Value009690d0 *default50; /* +0x50: what an empty slot of the array at +0x1e8 gets */
    Value009690d0 *default58; /* +0x58: the same for +0x218 */
    Value009690d0 *default60; /* +0x60: the same for +0x248 */
    u8 unknown68[0x10];
    Value009690d0 *default78; /* +0x78: the same for +0x230 */
    u8 unknown80[0x168];
    Slots009690d0 slots1e8; /* +0x1e8 */
    u8 unknown200[0x18];
    Slots009690d0 slots218; /* +0x218 */
    Slots009690d0 slots230; /* +0x230 */
    Slots009690d0 slots248; /* +0x248 */
};

struct Object009690d0 { /* derived name */
    u8 unknown0[0x10];
    Target009690d0 *target; /* +0x10 */
    u8 unknown18[0x58];
    int unknown70; /* +0x70: whether a slot other than the first, or an object, was set last (FUN_009694b0) */
};

#endif
