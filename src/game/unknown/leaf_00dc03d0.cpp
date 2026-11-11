/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_libc.h"

/* derived names: the script C function "clock" of the "os" library (the
 * table at 0x16bcd00, leaf_00de69d0.cpp's "clockpersecond" beside it):
 * pushes the whole seconds of the processor time, clock() divided by
 * 1000000 as an int, as a number, and returns one result. The C function's
 * own name is unknown. */
int FUN_00dc03d0(lua_State *state) /* derived name */
{
    const int seconds = clock() / 1000000;
    HksObject *top = state->top;
    top->value.number = seconds;
    top->type = 3;
    state->top = top + 1;
    return 1;
}
