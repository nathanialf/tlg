/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_hks.h"
#include "tlg_libc.h"

/* derived names: the script C function FUN_00874ec0 registers (lea at
 * 0x8750ff) through FUN_00c87e30 under the script name
 * "Guide_SetExtraParameter" (its description "Guide_SetExtraParameter(bool
 * isNoCatch)"): when the first argument's string names the parameter
 * "CatchObj" (interned as a copy: the last argument of FUN_013baad0 0; a
 * null or empty string names nothing), the byte at 0x58325e8 becomes the
 * second argument's truth; returns 0 (no results). The parameter's name is
 * a static of the function (at 0x581e3d8), interned once (as a copy) and
 * destroyed at exit with Name's destructor. The C function's own name is
 * unknown. */
extern const char D_159992a[9]; /* "CatchObj" */
extern bool D_58325e8;          /* derived name: whether the guide catches no object */

int FUN_00875da0(lua_State *state) /* derived name */
{
    const char *string = 0;
    if (state->base < state->top)
        string = FUN_00db6b20(state, state->base, 0);
    const unsigned interned = Name::intern(string);
    Name name(interned);
    static Name D_581e3d8(D_159992a, false);
    if (name == D_581e3d8)
        D_58325e8 = toBoolean(state, 2);
    return 0;
}
