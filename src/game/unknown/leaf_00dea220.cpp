/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function registered as "getfenv" (the
 * library table entry at 0x16bc8b0, a HksLibraryEntry): with at least one
 * argument, pushes a
 * copy of the last one (FUN_00db7b30 copies it to the top; nil when it is
 * below the frame's base) and returns it (1 result); else returns 0. The
 * copy's callee and the C function's own name are not traced. */
void FUN_00db7b30(lua_State *state, const HksObject *from, HksObject *to); /* derived name */

int FUN_00dea220(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count > 0) {
        HksObject *top = state->top;
        const HksObject *last = top - 1;
        if (last < state->base)
            top->type = 0;
        else
            FUN_00db7b30(state, last, top);
        state->top = top + 1;
        return 1;
    }
    return 0;
}
