/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object016b4ce0.h"
#include "tlg_hks.h"
#include "tlg_libc.h"

/* derived names: the entry the first argument's string names (interned as
 * a copy; a null or empty string names nothing) given the second argument's
 * number as its count, shown when it is marked at +0xd0 and the count is
 * not 0 */
void FUN_00b16110(Object016b4ce0 *self, lua_State *state) /* derived name */
{
    const char *string = 0;
    if (state->base < state->top)
        string = FUN_00db6b20(state, state->base, 0);
    const unsigned interned = Name::intern(string);
    Name name(interned);
    const int count = toNumber(state, 2);
    Entry016b4ce0 *entry = Entry016b4ce0::of(FUN_01390e90(self, name));
    if (!entry)
        return;
    self->setCount(entry, count, entry->shownD0);
}
