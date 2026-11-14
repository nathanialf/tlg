/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_libc.h"
#include "tlg_game_object0581f740.h"

/* derived names: the script C function registered under "MSC_GetFadeOut" (through
 * FUN_00c87e30 with the description "MSC_GetFadeOut()"): with any argument it formats
 * the parameter-count message into a local buffer that nothing reads, then
 * pushes the float at +0x48 of the object the pointer at 0x581f740 holds as a number and returns 1 (one result). The C function's own
 * name is unknown. */
int FUN_008e54a0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count != 0) {
        char message[128];
        sprintf(message, "%s needs %d parameters", "MSC_GetFadeOut", 0);
    }
    HksObject *top = state->top;
    top->value.number = D_581f740->fadeOut;
    top->type = 3;
    state->top = top + 1;
    return 1;
}
