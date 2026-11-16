/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_fade013d2490.h"

/* derived name: a copy of FUN_013d2490 (leaf_013d2490.cpp, where the fade's
 * update is described) over its own unit's constants (1e-5 and 1.0, as
 * there); slot 5 of Object016bfc70 (leaf_013d9d50.cpp). */
void FUN_013d8910(Fade013d2490 *self) /* derived name */
{
    FadeTarget013d2490 *target = self->owner->target;
    for (int i = 0; i < target->count; ++i) {
        self->entries[i].unknown40 = 0;
        target->entries[i].unknown90 = 0;
    }
    self->unknown6c = 0;
    if (self->state == 1) {
        if (self->fadeIn < 0.00001f) {
            self->state = 2;
            self->level = 1.0f;
        } else {
            self->level += self->owner->clock->step / self->fadeIn;
            if (self->level >= 1.0f) {
                self->state = 2;
                self->level = 1.0f;
            }
        }
    } else if (self->state == 3) {
        self->level -= self->owner->clock->step / self->fadeOut;
        if (!(self->level > 0.0f)) {
            self->state = 0;
            self->level = 0.0f;
        }
    }
}
