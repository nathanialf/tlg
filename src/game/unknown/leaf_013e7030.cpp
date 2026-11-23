/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_fade013e7030.h"

using namespace fade013e7030;

/* derived names: slot 3 of the vtable at 0x16d4d98 (its word at 0x16d4db0;
 * slots 0 and 1 0x13e8390 and 0x13e84b0): one step of the sine fade
 * (tlg_game_fade013e7030.h): the time moved by the control's step over the
 * length, forward or back by the direction (each arm its own `+=` or `-=`:
 * the time's load is hoisted above the select and the sum keeps it first,
 * `vaddss xmm0, xmm1, xmm0`), clamped to [0, 1], and the value a sine ease in
 * and out of it. One of 25 byte-identical slots of the classes at 0x16d4xxx
 * to 0x16d7xxx (0x13e90a0, 0x13effa0, ... 0x14941f0). The classes are not
 * traced. */
void FUN_013e7030(Object013e7030 *self) /* derived name */
{
    if (self->control->restart) {
        self->control->state = 0;
        self->value = 0.0f;
        self->time = 0.0f;
    }
    self->restarted = self->control->restart;
    self->restarted =
        self->control->state == 0 && self->control->direction == 1 ? 1 : self->restarted;
    if (self->control->direction == 1)
        self->time += self->control->step / self->duration;
    else
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
