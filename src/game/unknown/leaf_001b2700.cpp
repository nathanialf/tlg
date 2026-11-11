/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "IsTakeScreenShot" (FUN_001bd010, lea
 * at 0x1db39f; its help "IsTakeScreenShot()"): pushes whether the int at
 * +0x284 of the record at +0x48 of the object the pointer at 0x5938c40 holds
 * is nonzero and returns one result. */
struct Member05938c40_48 { /* derived name */
    u8 unknown0[0x284];
    int unknown284;
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x48];
    Member05938c40_48 *unknown48;
};

extern Object05938c40 *D_5938c40;

int FUN_001b2700(lua_State *state) /* derived name */
{
    bool value = D_5938c40->unknown48->unknown284 != 0;
    HksObject *top = state->top;
    top->value.boolean = value;
    top->type = 1;
    state->top = top + 1;
    return 1;
}
