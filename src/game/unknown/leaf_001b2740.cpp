/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_hks.h"
#include "tlg_libc.h"

/* derived names: the script C functions "SetScreenShotPath" and
 * "SetScreenShotFileName" (FUN_001db8b0 registers them through
 * FUN_00c87e30, lea at 0x1db3bc and 0x1db3d9): with an argument, its string
 * (none for an argument that holds none) is looked up as a name, without
 * interning it, and assigned to the screenshot's path at +0x290 or file name
 * at +0x294 of the member at +0x48 of the object the pointer at 0x5938c40
 * holds (the member read before the name is made); return 0 (no results). */
struct Member05938c40_48 /* derived name */
{
    u8 unknown0[0x290];
    Name screenShotPath;     /* +0x290 */
    Name screenShotFileName; /* +0x294 */
};

struct Object05938c40 /* derived name */
{
    u8 unknown0[0x48];
    Member05938c40_48 *unknown48; /* +0x48 */
};

extern Object05938c40 *D_5938c40;

int FUN_001b2740(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count > 0) {
        const char *string = 0;
        if (state->base < state->top)
            string = FUN_00db6b20(state, state->base, 0);
        Member05938c40_48 *member = D_5938c40->unknown48;
        Name name;
        if (string && *string)
            name.index = FUN_013baad0(string, FUN_013bad90(string), strlen(string), false);
        member->screenShotPath = name;
    }
    return 0;
}

int FUN_001b2850(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count > 0) {
        const char *string = 0;
        if (state->base < state->top)
            string = FUN_00db6b20(state, state->base, 0);
        Member05938c40_48 *member = D_5938c40->unknown48;
        Name name;
        if (string && *string)
            name.index = FUN_013baad0(string, FUN_013bad90(string), strlen(string), false);
        member->screenShotFileName = name;
    }
    return 0;
}
