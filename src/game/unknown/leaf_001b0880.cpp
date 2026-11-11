/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "TricoGame_GetGameSpeed" (FUN_001bd010
 * registers it through FUN_00c87e30, lea at 0x1db15b, signature string "speed
 * = TricoGame_GetGameSpeed()"): pushes the float at +0x140 of the object the
 * pointer at 0x57c9390 holds as a number and returns one result. The C
 * function's own name is unknown. */
struct Object057c9390 { /* derived name */
    u8 unknown0[0x140];
    float unknown140;
};

extern Object057c9390 *D_57c9390;

int FUN_001b0880(lua_State *state) /* derived name */
{
    HksObject *top = state->top;
    top->value.number = D_57c9390->unknown140;
    top->type = 3;
    state->top = top + 1;
    return 1;
}
