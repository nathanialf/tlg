/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"
#include "tlg_libc.h"

/* derived names: a script C function: pushes the processor time clock()
 * returns as a number and returns 1 (one result). */
int FUN_00de6990(lua_State *state) /* derived name */
{
    float now = clock();
    HksObject *top = state->top;
    top->value.number = now;
    top->type = 3;
    state->top = top + 1;
    return 1;
}
