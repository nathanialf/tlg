/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: a component (FUN_0046a860 hands one found by its type,
 * FUN_00abec10 its own object) with an array of 32-bit codes at +0x400;
 * FUN_0043c0c0 appends a code of at most 0x9a to it and ignores a larger
 * one (`cmp r14d, 0x9a; ja`, unsigned: tlg_game_array.h's push). The
 * callers pass 0x55 and 126; what the codes name is not traced. */
struct Component0043c0c0 {    /* derived name */
    u8 unknown0[0x400];       /* not traced */
    Array05943280<u32> codes; /* +0x400 */
};

void FUN_0043c0c0(Component0043c0c0 *self, u32 code) /* derived name */
{
    if (code <= 0x9a)
        self->codes.push(code);
}
