/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_level0140b610.h"

/* derived name: one step of the level (tlg_game_level0140b610.h; one of two
 * byte-identical copies, 0x140b610 and 0x1490450); a level already outside [0, 1] is
 * only brought back into it */
void FUN_01490450(Level0140b610 *self, int rising) /* derived name */
{
    self->started = self->rising == 0 && rising == 1;
    self->rising = rising;
    float level = self->level;
    if (level < 0.0f) {
        level = 0.0f;
    } else if (level > 1.0f) {
        level = 1.0f;
    } else {
        float delta = self->owner->clock->step / self->length;
        if (rising == 0)
            delta = -delta;
        level += delta;
        if (level < 0.0f)
            level = 0.0f;
        else
            level = minimum(level, 1.0f);
    }
    self->level = level;
}
