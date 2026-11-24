/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d3b98.h"

/* derived names: the class of the vtable at 0x16d3b48 (made by FUN_013d31a0,
 * destroyed by 0x13d35e0): an array of 32-bit values at +0x18, five parts of
 * the class of the vtable at 0x16d3b98 from +0x30 and an Object013d6840 at
 * +0x210 (its values at +0x228). The rest is not traced. */
struct Object013d3b20 { /* derived name */
    u8 unknown0[0x18];
    Array05943280<u32> values18; /* +0x18 */
    Object016d3b98 part30;       /* +0x30 */
    Object016d3b98 part90;       /* +0x90 */
    Object016d3b98 partf0;       /* +0xf0 */
    Object016d3b98 part150;      /* +0x150 */
    Object016d3b98 part1b0;      /* +0x1b0 */
    Object013d6840 last;         /* +0x210 */
};

/* FUN_013d3b20: slot 2 of the vtable at 0x16d3b48 (FUN_00f59e00 and
 * FUN_0121a680 call it too): the values made 148 zeros, each part reset
 * (FUN_013d4910, called), then the last member's reset (0x13d4870) in
 * line */
void FUN_013d3b20(Object013d3b20 *self) /* derived name */
{
    self->values18.resize(148);
    for (unsigned i = 0; i < self->values18.size(); ++i)
        self->values18[i] = 0;
    self->part30.reset();
    self->part90.reset();
    self->partf0.reset();
    self->part150.reset();
    self->part1b0.reset();
    self->last.reset();
}
