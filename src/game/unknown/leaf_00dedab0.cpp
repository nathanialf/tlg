/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived names: a script C function: pushes the value of the shared state's
 * array at +0x208 that the type tag of its first argument (its low four bits)
 * plus 27 selects, and returns 1 (one result). */
// NONMATCHING: the index's add of 27 stays in 32 bits before the zero extension in
// the base (`and eax, 0xf; add eax, 0x1b; shl rax, 4`, the array at +0x208), as the
// prebuilt 3.8.1 and 3.9.1 compile this; 4.0.0 folds 27 * 16 into the displacement.
int FUN_00dedab0(lua_State *state) /* derived name */
{
    *state->top = state->global->unknown208[(state->base->type & 0xf) + 27];
    ++state->top;
    return 1;
}
