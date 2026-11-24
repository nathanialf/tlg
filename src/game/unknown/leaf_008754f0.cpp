/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object016b4ce0.h"
#include "tlg_hks.h"
#include "tlg_libc.h"

/* derived names: the script C function FUN_00874ec0 registers (lea at
 * 0x874f86) through FUN_00c87e30 under the script name "Guide_fadeIn" (its
 * description "Guide_fadeIn(time,keycode)"): the name the second argument's
 * string names (interned as a copy: the last argument of FUN_013baad0
 * 0; a null or empty string names nothing) and the third argument's truth
 * passed with the object the pointer at 0x581e3a8 holds to its remove (FUN_00b16a90);
 * returns 0 (no results). The C function's own name is unknown; the callee's
 * return type is not traced. */
extern Object016b4ce0 *D_581e3a8;

// The argument's truth keeps its select (`cmovae rax, rcx; jae` at 0x875575, toBoolean in tlg_hks.h).
// The base keeps the name's index in r14d across FUN_00b16a90 and the release's `lock xadd`
// by the memory dependence rule (tools/patches/llvm-3.7.1-atomic-01-ordered-rmw-uncaptured-local.patch).
int FUN_008754f0(lua_State *state) /* derived name */
{
    const char *string = 0;
    if (state->base + 1 < state->top)
        string = FUN_00db6b20(state, state->base + 1, 0);
    const unsigned interned = Name::intern(string);
    Name name(interned);
    const bool every = toBoolean(state, 3);
    D_581e3a8->remove(name, every);
    return 0;
}
