/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "clockpersecond" of the "os" library (the table at 0x16bcd00):
 * pushes the number 1000000 and returns one result. The C function's own name is unknown. */
int FUN_00de69d0(lua_State *state) /* derived name */
{
    HksObject *top = state->top;
    top->value.number = 1000000.0f;
    top->type = 3;
    state->top = top + 1;
    return 1;
}
