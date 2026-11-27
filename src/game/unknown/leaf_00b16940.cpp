/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object016b4ce0.h"
#include "tlg_hks.h"
#include "tlg_libc.h"

/* derived names: the entry the first argument's string names (interned as
 * a copy; a null or empty string names nothing) finished: when the second
 * argument is true its level (+0xd8) is raised by one up to its limit
 * (+0xdc; 1 with no limit), then its count is cleared and it is hidden */
void FUN_00b16940(Object016b4ce0 *self, lua_State *state) /* derived name */
{
    const char *string = 0;
    if (state->base < state->top)
        string = FUN_00db6b20(state, state->base, 0);
    const unsigned interned = Name::intern(string);
    Name name(interned);
    Entry016b4ce0 *entry = Entry016b4ce0::of(FUN_01390e90(self, name));
    if (entry) {
        if (toBoolean(state, 2)) {
            if (entry->limitDC)
                entry->levelD8 =
                    entry->levelD8 < entry->limitDC ? entry->levelD8 + 1 : entry->limitDC;
            else
                entry->levelD8 = 1;
        }
        entry->countC8 = 0;
        FUN_013907f0(self, entry, false);
    }
}
