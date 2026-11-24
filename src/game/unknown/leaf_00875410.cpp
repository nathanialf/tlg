/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object016b4ce0.h"
#include "tlg_hks.h"
#include "tlg_libc.h"

/* derived names: the script C function FUN_00874ec0 registers (lea at
 * 0x874f4c) through FUN_00c87e30 under the script name "Guide_CountUpNorma"
 * (its description "Guide_CountUpNorma(name,noruma)"): the name the first
 * argument's string names (interned as a copy: the last argument of
 * FUN_013baad0 0; a null or empty string names nothing) passed with the
 * object the pointer at 0x581e3a8 holds to its countDown (FUN_00b16780); returns 0 (no
 * results). The C function's own name is unknown; the callee's return type
 * is not traced. */
extern Object016b4ce0 *D_581e3a8;

// The name is made from its index once the index is known (Name::intern, one store at 0x87547c): with the
// name made first and assigned in the test, JumpThreading copies its constructor into the path that skips
// FUN_00db6b20 and the slot's address becomes a phi that hides it from the rule below.
// The base keeps the name's index in ebx across FUN_00b16780 and the release's `lock xadd`
// by the memory dependence rule (tools/patches/llvm-3.7.1-atomic-01-ordered-rmw-uncaptured-local.patch).
int FUN_00875410(lua_State *state) /* derived name */
{
    const char *string = 0;
    if (state->base < state->top)
        string = FUN_00db6b20(state, state->base, 0);
    const unsigned interned = Name::intern(string);
    Name name(interned);
    D_581e3a8->countDown(name);
    return 0;
}
