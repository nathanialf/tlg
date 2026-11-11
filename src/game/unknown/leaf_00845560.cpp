/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "IsVolumeViewerMode" (FUN_001db8b0
 * registers it through FUN_00c87e30, lea at 0x1ddc98, signature string
 * "sw = IsVolumeViewerMode()"): pushes 1 or 0 as a number, as the int at
 * +0xe8 of the record the pointer at +0x60 of the object the pointer at
 * 0x57c9390 holds is nonzero or not, and returns one result. The C
 * function's own name is unknown. */
struct Member057c9390_60 /* derived name */
{
    u8 unknown0[0xe8];
    int unknownE8; /* +0xe8 */
};

struct Object057c9390 /* derived name */
{
    u8 unknown0[0x60];
    Member057c9390_60 *unknown60; /* +0x60 */
};

extern Object057c9390 *D_57c9390;

// NONMATCHING: the select lowered to a branch (D49) lays out the other way: the base
// loads the member before the top and falls through to 0.0 (`jne` to the 1.0 load),
// where this loads the top first and falls through to 1.0.
int FUN_00845560(lua_State *state) /* derived name */
{
    const Member057c9390_60 *member = D_57c9390->unknown60;
    HksObject *top = state->top;
    top->value.number = member->unknownE8 != 0 ? 1.0f : 0.0f;
    top->type = 3;
    state->top = top + 1;
    return 1;
}
