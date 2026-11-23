/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: sets the count of the array of ints at +0x70 when it
 * differs and clears the elements (tlg_game_array.h's resize constructs
 * nothing for an int), as FUN_00a18a70 does for its array at +0x88; called
 * once, by FUN_001b37c0 */
struct Object00a189b0 { /* derived name */
    u8 unknown0[0x70];
    Array05943280<int> values; /* +0x70 */
};

/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: cost 200 at the
 * link, over its threshold of 175: one signature changes no row) */
void FUN_00a189b0(Object00a189b0 *self, unsigned count) /* derived name */
{
    if (self->values.size() == count)
        return;
    self->values.resize(count);
    for (unsigned i = 0; i < self->values.size(); ++i)
        self->values[i] = 0;
}
