/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0141ebc0.h"

/* derived names: slot 2 of the vtable at 0x16d5d08: the value is raised by
 * half the control's step up to 1 while every weight is still (their sum
 * 0.01 at most), and dropped to 0 otherwise; full when it is within 1e-5
 * of 1. */
void FUN_0141ebc0(Object0141ebc0 *self) /* derived name */
{
    const float *a = self->weights140;
    const float *b = self->weights160;
    const Part0141ebc0 *part = self->owner->part;
    const float sum = a[0] + a[1] + b[0] + b[1] + b[2] + b[3] + b[4] + b[5] + b[6] +
                      part->weight1d90 + part->weight1dc8;
    float value;
    if (sum > 0.01f)
        value = 0.0f;
    else if (self->level > 1.0f)
        value = 1.0f;
    else {
        value = self->level + self->control->step * 0.5f;
        value = value < 1.0f ? value : 1.0f;
    }
    self->level = value;
    self->full = fabsf(self->level - 1.0f) <= 1e-5f;
}
