/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_hks.h"
#include "tlg_libc.h"

/* derived names: the script C function FUN_00a64050 registers (lea at
 * 0xa642aa) through FUN_00c87e30 under the script name "Subtitle_Start"
 * (its description "Subtitle_Start(name)"): the name the first
 * argument's string names (looked up, not interned: the last argument of
 * FUN_013baad0 0; a null or empty string names nothing) passed with the
 * object the pointer at 0x5828450 holds to FUN_00b73e10; pushes its answer and returns 1 (one
 * result). The C function's own name is unknown; the callee answers a bool
 * (`movzx eax, al` at 0xa64537). */
struct Object05828450; /* derived name */

extern Object05828450 *D_5828450;

bool FUN_00b73e10(Object05828450 *object, const Name &name); /* derived name */

// NONMATCHING: the empty name's 0 (module, size the base's): the base makes it twice, at the
// entry and again before FUN_00db6b20 (`xor r14d, r14d` both times), the build once; the callee is not written,
// so the module cannot know it leaves the name alone (the census's one unwritten callee)
// The base keeps the name's index in r14d across FUN_00b73e10 and the release's `lock xadd`
// by the memory dependence rule (tools/patches/llvm-3.7.1-atomic-01-ordered-rmw-uncaptured-local.patch).
int FUN_00a644b0(lua_State *state) /* derived name */
{
    const char *string = 0;
    if (state->base < state->top)
        string = FUN_00db6b20(state, state->base, 0);
    Name name;
    if (string && *string)
        name.index = FUN_013baad0(string, FUN_013bad90(string), strlen(string), false);
    pushBoolean(state, FUN_00b73e10(D_5828450, name));
    return 1;
}
