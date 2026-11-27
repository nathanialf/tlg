/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object016b4ce0.h"
#include "tlg_hks.h"
#include "tlg_libc.h"

/* derived names: a script C function: the entry the first argument's
 * string names (interned as a copy; a null or empty string names nothing)
 * shown or hidden by the second argument's truth when the guide's level
 * (+0x110) reaches the entry's (+0xd4); returns 0 (no results). FUN_00874ec0 registers it (lea at 0x874ed4)
 * through FUN_00c87e30 under the script name "Guide_SetEnable" (its description
 * "Guide_SetEnable(name,bool)"). */
int FUN_008751a0(lua_State *state) /* derived name */
{
    const char *string = 0;
    if (state->base < state->top)
        string = FUN_00db6b20(state, state->base, 0);
    const unsigned interned = Name::intern(string);
    Name name(interned);
    const bool shown = toBoolean(state, 2);
    Object016b4ce0 *guide = D_581e3a8;
    Entry016b4ce0 *entry = Entry016b4ce0::of(FUN_01390e90(guide, name));
    if (entry && guide->level() >= entry->levelD4)
        FUN_013907f0(guide, entry, shown);
    return 0;
}
