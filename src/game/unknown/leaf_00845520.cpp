/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "SetVolumeViewerMode" (FUN_001db8b0
 * registers it through FUN_00c87e30, lea at 0x1ddc73, signature string
 * "SetVolumeViewerMode('sw')"): stores at +0xe8 of the record at +0x60 of the
 * object the pointer at 0x57c9390 holds the number FUN_00db6f40 reads from the
 * first argument, truncated to an int, or 0 without an argument (the `jae`
 * lands on the store with eax 0), and returns 1. The C function's own name is
 * unknown; FUN_00db6f40 is taken to read a value as a float. */
struct Member057c9390_60 { /* derived name */
    u8 unknown0[0xe8];
    int unknowne8;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x60];
    Member057c9390_60 *unknown60;
};

extern Object057c9390 *D_57c9390;

float FUN_00db6f40(lua_State *state, const HksObject *value); /* derived name */

int FUN_00845520(lua_State *state) /* derived name */
{
    int mode = 0;
    if (state->base < state->top)
        mode = FUN_00db6f40(state, state->base);
    D_57c9390->unknown60->unknowne8 = mode;
    return 1;
}
