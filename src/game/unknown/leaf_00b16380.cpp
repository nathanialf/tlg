/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object016b4ce0.h"
#include "tlg_hks.h"
#include "tlg_libc.h"

/* derived names: the entry the first argument's string names (interned as
 * a copy; a null or empty string names nothing) counted again from its
 * total: when the second argument is true its level is cleared and it is
 * shown when marked at +0xd0; else only while its level is below its limit
 * (+0xdc, none when 0), and shown whenever the total is not 0 */
// NONMATCHING: 825 against 1022 bytes: every instruction to the fade's start is the base's, but
// the build holds one copy of setCount()'s fade (from `je` on the full mark, 0xb164e1 and 0xb16583)
// where the base keeps one for each of the two calls (0xb16596 and 0xb16663, the same bytes). The
// unit keeps both inlined copies, and so does the link stage: -print-after-all over the link's
// pipeline on this unit's module shows two fdiv and two calls of FUN_013907f0 after every pass; in
// code generation both copies last to Expand ISel Pseudo-instructions and become one in Control
// Flow Optimizer (BranchFolder's tail merge, the first post-RA pass that changes their count).
// The base's two copies are byte-identical and share the exit, so at its tail merge they were not
// identical machine instructions or were refused as candidates: not traced further (round 586C)
void FUN_00b16380(Object016b4ce0 *self, lua_State *state) /* derived name */
{
    const char *string = 0;
    if (state->base < state->top)
        string = FUN_00db6b20(state, state->base, 0);
    const unsigned interned = Name::intern(string);
    Name name(interned);
    Entry016b4ce0 *entry = Entry016b4ce0::of(FUN_01390e90(self, name));
    if (!entry)
        return;
    if (toBoolean(state, 2)) {
        entry->levelD8 = 0;
        self->setCount(entry, entry->totalCC, entry->shownD0);
    } else if (entry->limitDC <= 0 || entry->levelD8 < entry->limitDC) {
        self->setCount(entry, entry->totalCC, true);
    }
}
