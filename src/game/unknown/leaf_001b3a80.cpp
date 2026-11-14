/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "PlayGoIsDialogOpen" (FUN_001bd010, lea
 * at 0x1db70a): pushes whether the int at +0xc of the record at +0xf58 of the
 * object the pointer at 0x5938c40 holds is nonzero and returns one result. */
struct Member05938c40_f58 { /* derived name */
    u8 unknown0[0xc];
    int unknownc;
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0xf58];
    Member05938c40_f58 *unknownf58;
};

extern Object05938c40 *D_5938c40;

int FUN_001b3a80(lua_State *state) /* derived name */
{
    bool value = D_5938c40->unknownf58->unknownc != 0;
    HksObject *top = state->top;
    top->value.boolean = value;
    top->type = 1;
    state->top = top + 1;
    return 1;
}
