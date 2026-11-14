/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "Overlay_StaffrollIsChangeStepEnd"
 * (FUN_001db8b0, lea at 0x1dd48d): pushes whether the int at +0x74 of the
 * record at +0x128 of the object the pointer at 0x57c9390 holds is zero and
 * returns one result. */
struct Member057c9390_128 { /* derived name */
    u8 unknown0[0x74];
    int unknown74;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x128];
    Member057c9390_128 *unknown128;
};

extern Object057c9390 *D_57c9390;

int FUN_0020e650(lua_State *state) /* derived name */
{
    bool value = D_57c9390->unknown128->unknown74 == 0;
    HksObject *top = state->top;
    top->value.boolean = value;
    top->type = 1;
    state->top = top + 1;
    return 1;
}
