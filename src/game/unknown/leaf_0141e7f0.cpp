/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0141ebc0.h"

using namespace fade013e7030;

/* derived names: slot 3 of the vtable at 0x16d5d08: the sine fade of
 * FUN_013e7030 (leaf_013e7030.cpp) restarted also on the owner's part's
 * state 1 and steered by the owner's direction at +0x1b4, the time stepped only while
 * it is within [0, 1], then clamped; the phase at +0x1d8 restarts with the
 * fade and turns by a quarter of the step, wrapped past 1. The class is not
 * traced. */
void FUN_0141e7f0(Object0141ebc0 *self) /* derived name */
{
    if (self->control->restart || self->owner->part->state == 1) {
        self->control->state = 0;
        self->value = 0.0f;
        self->time = 0.0f;
    }
    const int direction = self->owner->direction;
    self->restarted = self->control->state == 0 && direction == 1;
    float time = self->time;
    if (time < 0.0f)
        time = 0.0f;
    else if (time > 1.0f)
        time = 1.0f;
    else {
        const float step = self->control->step / self->duration;
        time = clamp(time + (direction ? step : -step), 0.0f, 1.0f);
    }
    self->time = time;
    const float t = self->time;
    if (t < 0.5f)
        self->value = easeInSine(t * 2.0f) * 0.5f;
    else
        self->value = easeOutSine((t - 0.5f) * 2.0f) * 0.5f + 0.5f;
    self->control->state = direction == 1 ? 1 : self->value > 1e-8f ? 2 : 0;
    if (self->restarted)
        self->phase = 0.0f;
    self->phase += self->control->step * 0.25f;
    if (self->phase > 1.0f)
        self->phase -= 1.0f;
}
