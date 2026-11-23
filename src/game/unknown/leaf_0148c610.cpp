/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_fade013e7030.h"

using namespace fade013e7030;

/* derived names: slot 3 of the vtable at 0x16d7c00: byte for byte FUN_01407460's (leaf_01407460.cpp). */
void FUN_0148c610(Object01407460 *self) /* derived name */
{
    FadeControl013e7030 *control = self->control;
    if (self->owner->control->state == 1 || (control->restart && control->state != 1)) {
        control->state = 0;
        self->value = 0.0f;
        self->time = 0.0f;
    }
    self->restarted = self->control->state == 0 && self->control->direction == 1;
    if (self->control->direction == 1) {
        if (self->owner->control->restart == 1 && self->owner->control->state == 1)
            self->time = 1.0f;
        self->time += self->control->step / self->duration;
    } else
        self->time -= self->control->step / self->duration;
    self->time = clamp(self->time, 0.0f, 1.0f);
    const float t = self->time;
    if (t < 0.5f)
        self->value = easeInSine(t * 2.0f) * 0.5f;
    else
        self->value = easeOutSine((t - 0.5f) * 2.0f) * 0.5f + 0.5f;
    if (self->control->direction == 1)
        self->control->state = 1;
    else
        self->control->state = self->value > 1e-8f ? 2 : 0;
}
