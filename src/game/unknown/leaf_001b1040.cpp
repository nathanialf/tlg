/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "TricoGame_IsGamePause" (FUN_001bd010
 * registers it through FUN_00c87e30, lea at 0x1db243, signature string
 * "isPaused = IsGamePause()"): pushes whether the int at +0x1bc of the object
 * the pointer at 0x5938c40 holds is nonzero, as a bool, and returns one
 * result. The C function's own name is unknown. */
struct Object05938c40 { /* derived name */
    u8 unknown0[0x1bc];
    int unknown1bc;
};

extern Object05938c40 *D_5938c40;

int FUN_001b1040(lua_State *state) /* derived name */
{
    HksObject *top = state->top;
    top->value.boolean = D_5938c40->unknown1bc != 0;
    top->type = 1;
    state->top = top + 1;
    return 1;
}
