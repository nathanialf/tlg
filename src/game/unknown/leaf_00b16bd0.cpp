/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b4ce0.h"
#include "tlg_hks.h"
#include "tlg_libc.h"

/* derived names: the script's Guide_SetIgnoreFade(keycode, isIgnore)
 * (FUN_00875780 hands it the frame): the name the first argument's string
 * names (interned as a copy: the last argument of FUN_013baad0 0; a null or
 * empty string names nothing) is ignored by the fade when the second
 * argument is true: added to the names at +0xd8 unless it is there already,
 * and every copy of it taken out of the names at +0xc0, last first, compared
 * by their strings (+0xb8 cleared once none are left); when it is false the
 * name is taken out of the names at +0xd8. The removals are the array's
 * removeSwap, out of line (FUN_002db3e0). */
// NONMATCHING: registers (module, 595 bytes against 617): the base clears r13d at the entry (the
// truth's select's null and its false, widened to r13d by `movzx r13d, cl` and tested after the
// search, 0xb16ca1) and makes the name's 0 there too (`mov r12d, 0`), spilling the index whole
// (`mov [rbp-0x30], r12`); the build keeps the truth in al and makes the select's null in its own
// block. The search, the push and the removal loop are the base's in shape
void Object016b4ce0::setIgnoreFade(lua_State *state)
{
    const char *string = 0;
    if (state->base < state->top)
        string = FUN_00db6b20(state, state->base, 0);
    const unsigned interned = Name::intern(string);
    Name name(interned);
    const bool ignore = toBoolean(state, 2);
    const int index = namesD8.indexOf(name);
    if (ignore) {
        if (index < 0) {
            namesD8.push(name);
            const int count = namesC0.size();
            if (count > 0) {
                for (s64 i = count; i > 0; --i)
                    if (namesC0.begin()[i - 1].string() == name.string())
                        namesC0.removeSwap(i - 1);
                if (namesC0.size() == 0)
                    activeB8 = 0;
            }
        }
    } else if (index >= 0) {
        namesD8.removeSwap(index);
    }
}
