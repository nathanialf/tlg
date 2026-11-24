/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_hks.h"
#include "tlg_libc.h"

/* derived names: the script C function FUN_00a64050 registers (lea at
 * 0xa642ef) through FUN_00c87e30 under the script name "Subtitle_PreLoad"
 * (its description "Subtitle_PreLoad(name)"): the name the first
 * argument's string names (looked up, not interned: the last argument of
 * FUN_013baad0 0; a null or empty string names nothing) passed with the
 * object the pointer at 0x5828450 holds to FUN_00b739c0; returns 0 (no
 * results). The C function's own name is unknown; the callee's return type
 * is not traced. */
struct Object05828450; /* derived name */

extern Object05828450 *D_5828450;

void FUN_00b739c0(Object05828450 *object, const Name &name); /* derived name */

// NONMATCHING: the empty name's 0 (module, size the base's): the base makes it twice, at the
// entry and again before FUN_00db6b20 (`xor ebx, ebx` both times), the build once; the callee is not written,
// so the module cannot know it leaves the name alone (the census's one unwritten callee)
// The base keeps the name's index in ebx across FUN_00b739c0 and the release's `lock xadd`
// by the memory dependence rule (tools/patches/llvm-3.7.1-atomic-01-ordered-rmw-uncaptured-local.patch).
int FUN_00a645c0(lua_State *state) /* derived name */
{
    const char *string = 0;
    if (state->base < state->top)
        string = FUN_00db6b20(state, state->base, 0);
    Name name;
    if (string && *string)
        name.index = FUN_013baad0(string, FUN_013bad90(string), strlen(string), false);
    FUN_00b739c0(D_5828450, name);
    return 0;
}
