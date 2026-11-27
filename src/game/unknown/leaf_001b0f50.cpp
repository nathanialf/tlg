/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks_string.h"
#include "tlg_game_string01331840.h"

/* derived names: the script C function "CalcFnv1a" (FUN_001bd010, lea at
 * 0x1db209): the 32-bit FNV-1a hash of its first argument's string (each
 * character signed), returned as a string of eight hexadecimal digits.
 * The string is read only for an argument within the frame. The C
 * function's own name is unknown. */
int FUN_001b0f50(lua_State *state) /* derived name */
{
    HksObject *value = state->base;
    const char *string = value < state->top ? FUN_00db6b20(state, value, 0) : 0;
    u32 hash = 0x811c9dc5;
    u32 length = strlen(string);
    for (u32 i = 0; i < length; ++i)
        hash = (hash ^ string[i]) * 0x1000193;
    String01331840 text;
    FUN_01331840(&text, "%08x", hash);
    pushString(state, text.text);
    return 1;
}
