/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_hks.h"
#include "tlg_libc.h"

/* derived names: the script C function FUN_00874ec0 registers (lea at
 * 0x874f86) through FUN_00c87e30 under the script name "Guide_fadeIn" (its
 * description "Guide_fadeIn(time,keycode)"): the name the second argument's
 * string names (looked up, not interned: the last argument of FUN_013baad0
 * 0; a null or empty string names nothing) and the third argument's truth
 * passed with the object the pointer at 0x581e3a8 holds to FUN_00b16a90;
 * returns 0 (no results). The C function's own name is unknown; the callee's
 * return type is not traced. */
struct Object0581e3a8; /* derived name */

extern Object0581e3a8 *D_581e3a8;

void FUN_00b16a90(Object0581e3a8 *object, const Name &name, bool value); /* derived name */

// NONMATCHING: the empty name's 0 (module, 83 instructions against 82): the base makes it twice, at the
// entry and again before FUN_00db6b20 (`xor r14d, r14d` both times), the build once; the callee is not written,
// so the module cannot know it leaves the name alone (the census's one unwritten callee)
// The base keeps the name's index in r14d across FUN_00b16a90 and the release's `lock xadd`
// by the memory dependence rule (tools/patches/llvm-3.7.1-atomic-01-ordered-rmw-uncaptured-local.patch).
int FUN_008754f0(lua_State *state) /* derived name */
{
    const char *string = 0;
    if (state->base + 1 < state->top)
        string = FUN_00db6b20(state, state->base + 1, 0);
    Name name;
    if (string && *string)
        name.index = FUN_013baad0(string, FUN_013bad90(string), strlen(string), false);
    FUN_00b16a90(D_581e3a8, name, toBoolean(state, 3));
    return 0;
}
