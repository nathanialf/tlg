/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: sets the count of the array of ints at +0x88 when it
 * differs and clears the elements (tlg_game_array.h's resize constructs
 * nothing for an int); called once, by FUN_001b2f50 */
struct Object00a18a70 { /* derived name */
    u8 unknown0[0x88];
    Array05943280<int> values; /* +0x88 */
};

void FUN_00a18a70(Object00a18a70 *self, unsigned count) /* derived name */
{
    if (self->values.size() == count)
        return;
    self->values.resize(count);
    for (unsigned i = 0; i < self->values.size(); ++i)
        self->values[i] = 0;
}
