/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "Sound_GetDebugFlag" (FUN_00a44ab0
 * registers it through FUN_00c87e30, lea at 0xa44b37, signature string
 * "Sound_GetDebugFlag()"): pushes whether the int at +0x9c of the object the
 * pointer at 0x5827b50 holds is nonzero, as a bool, and returns one result.
 * The C function's own name is unknown. */
struct Object05827b50 { /* derived name */
    u8 unknown0[0x9c];
    int unknown9c;
};

extern Object05827b50 *D_5827b50;

int FUN_00a44f70(lua_State *state) /* derived name */
{
    HksObject *top = state->top;
    top->value.boolean = D_5827b50->unknown9c != 0;
    top->type = 1;
    state->top = top + 1;
    return 1;
}
