/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived names: a script C function: pushes the running thread (tag 8) and,
 * when it is the main thread, makes the pushed value nil instead (the main
 * thread is not a coroutine, as Lua's coroutine.running), and returns 1. */
int FUN_00deceb0(lua_State *state) /* derived name */
{
    HksObject *top = state->top;
    top->value.pointer = state;
    top->type = 8;
    bool isMain = state->global->mainThread == state;
    state->top = top + 1;
    if (isMain) {
        top->type = 0;
        state->top = top + 1;
    }
    return 1;
}
