/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "Overlay_IsEnd" (FUN_001db8b0
 * registers it through FUN_00c87e30, lea at 0x1dd44d): pushes whether the int
 * at +0xfc of the record the pointer at +0x128 of the object the pointer at
 * 0x57c9390 holds is 0 or 7, as a boolean, and returns one result. The C
 * function's own name is unknown. */
struct Member057c9390_128 /* derived name */
{
    u8 unknown0[0xfc];
    int unknownFc; /* +0xfc */
};

struct Object057c9390 /* derived name */
{
    u8 unknown0[0x128];
    Member057c9390_128 *unknown128; /* +0x128 */
};

extern Object057c9390 *D_57c9390;

// NONMATCHING: 9/16, the instructions and their order are the base's; the registers are not (the
// base keeps the stack top in rdx and the first compare's byte in cl, the build rcx and dl)
int FUN_0020e400(lua_State *state) /* derived name */
{
    int phase = D_57c9390->unknown128->unknownFc;
    HksObject *top = state->top;
    top->value.boolean = phase == 0 || phase == 7;
    top->type = 1;
    state->top = top + 1;
    return 1;
}
