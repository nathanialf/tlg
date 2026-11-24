/* src/include/tlg_game_foot013e8d20.h: a foot of a fading model, whose
 * velocity and contact FUN_013e8d20 and its twin FUN_0147f100 update (game
 * region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_FOOT013E8D20_H
#define TLG_GAME_FOOT013E8D20_H

#include "tlg_game_fade013d2490.h"
#include "tlg_game_name.h"
#include "tlg_math.h"

/* derived names: the model's state at +0x210: the feet's velocities through
 * the pointer at +0x1e88, indexed by each foot's slot; the contact ints at
 * +0x6fc and on (read by the callers FUN_00fdf160 and FUN_0124c8c0) are not
 * traced */
struct FadeState013e8d20 { /* derived name */
    u8 unknown0[0x1e88];
    Float4 *velocities; /* +0x1e88: the feet's velocities, set whole (the w lane copied as it is) */
};

/* derived names: a foot, 0x30 bytes (the callers pass +0x4d0 and +0x500 of
 * the model): the model, the slot of its velocity, the joint, its name and
 * the position of the last update */
struct Foot013e8d20 {         /* derived name */
    FadeModel013d4610 *model; /* +0x0 */
    s8 slot;                  /* +0x8: `movsx rsi, byte [rbx+8]` */
    int joint;                /* +0xc */
    Name name;                /* +0x10 */
    Float4A previous;         /* +0x20 */
};

void FUN_00fe1b70(const Name &first, const Name &second, const Name &third); /* derived name */

#endif
