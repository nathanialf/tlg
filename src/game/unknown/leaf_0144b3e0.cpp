/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_fade013e7030.h"

using namespace fade013e7030;

/* derived names: the owner of the class whose vtable is at 0x16d61d0: its
 * status and its control at +0x218 and +0x220. The rest is not traced. */
struct Owner0144b3e0 { /* derived name */
    u8 unknown0[0x218];
    OwnerStatus0145a4d0 *status;   /* +0x218 */
    OwnerControl0145a4d0 *control; /* +0x220 */
};

/* derived names: Object013e7030's fields with the owner above and the
 * length of the fall at +0x78 */
struct Object0144b3e0 { /* derived name */
    u8 unknown0[0x8];
    Owner0144b3e0 *owner;         /* +0x8 */
    FadeControl013e7030 *control; /* +0x10 */
    u8 unknown18[0x48];
    float value;    /* +0x60 */
    float time;     /* +0x64 */
    float duration; /* +0x68 */
    int restarted;  /* +0x6c */
    u8 unknown70[0x8];
    float fallDuration; /* +0x78 */
};

/* derived names: slot 3 of the vtable at 0x16d61d0: the sine fade of
 * FUN_013e7030 (leaf_013e7030.cpp) restarted also on the owner's state 1 or
 * its status flag at +0x130, rising only while the owner's flag at +0x1c is
 * clear, and falling over the length at +0x78. The class is not traced. */
void FUN_0144b3e0(Object0144b3e0 *self) /* derived name */
{
    if (self->control->restart || self->owner->control->state == 1 ||
        self->owner->status->flag130) {
        self->control->state = 0;
        self->value = 0.0f;
        self->time = 0.0f;
    }
    int rising = self->control->direction == 1;
    if (self->owner->control->flag1c)
        rising = 0;
    self->restarted = self->control->restart;
    self->restarted = self->control->state == 0 && rising == 1 ? 1 : self->restarted;
    if (rising == 1)
        self->time += self->control->step / self->duration;
    else
        self->time -= self->control->step / self->fallDuration;
    self->time = clamp(self->time, 0.0f, 1.0f);
    const float t = self->time;
    if (t < 0.5f)
        self->value = easeInSine(t * 2.0f) * 0.5f;
    else
        self->value = easeOutSine((t - 0.5f) * 2.0f) * 0.5f + 0.5f;
    self->control->state = rising == 1 ? 1 : self->value > 1e-8f ? 2 : 0;
}
