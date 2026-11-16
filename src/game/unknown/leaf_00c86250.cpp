/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_hks_string.h"
#include "tlg_libc.h"
#include "tlg_game_log.h"

/* derived names: the script C function registered under "Log" (its address
 * taken at 0xc846e0): asks the game's debug output (tlg_game_log.h, slot 2)
 * for the text of the first argument's number as an int, keeps its last 255
 * characters, pushes it (nil when there is none) and returns 1 (one
 * result). The C function's own name is unknown. */
int FUN_00c86250(lua_State *state) /* derived name */
{
    int number = toNumber(state, 1);
    const char *text = debugOutput().unknown2(number);
    size_t length = strlen(text);
    if (length > 255)
        pushString(state, text + ((int)length - 255));
    else
        pushString(state, text);
    return 1;
}
