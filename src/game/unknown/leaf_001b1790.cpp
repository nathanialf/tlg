/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "IsAsyncLoading" (FUN_001bd010, lea at
 * 0x1db2f1; its help "bool = IsAsyncLoading()"): pushes whether the int at
 * +0x100 of the record at +0x38 of the object the pointer at 0x5938c40 holds is
 * nonzero and returns one result. */
struct Member05938c40_38 { /* derived name */
    u8 unknown0[0x100];
    int unknown100;
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x38];
    Member05938c40_38 *unknown38;
};

extern Object05938c40 *D_5938c40;

int FUN_001b1790(lua_State *state) /* derived name */
{
    int loading = D_5938c40->unknown38->unknown100;
    HksObject *top = state->top;
    top->value.boolean = loading != 0;
    top->type = 1;
    state->top = top + 1;
    return 1;
}
