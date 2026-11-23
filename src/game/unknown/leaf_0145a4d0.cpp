/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_fade013e7030.h"

using namespace fade013e7030;

/* derived names: the owner of the class whose vtable is at 0x16d63d8:
 * its status and its control at +0x300 and +0x308. The rest is not traced. */
struct Owner0145a4d0 { /* derived name */
    u8 unknown0[0x300];
    OwnerStatus0145a4d0 *status;   /* +0x300 */
    OwnerControl0145a4d0 *control; /* +0x308 */
};

/* derived names: Object013e7030's fields with the owner above, the length
 * of the fall at +0x70, a flag at +0xa0 that makes the time the value, and
 * six weights at +0xa4 whose least sets the time while it is set */
struct Object0145a4d0 { /* derived name */
    u8 unknown0[0x8];
    Owner0145a4d0 *owner;         /* +0x8 */
    FadeControl013e7030 *control; /* +0x10 */
    u8 unknown18[0x48];
    float value;        /* +0x60 */
    float time;         /* +0x64 */
    float duration;     /* +0x68 */
    int restarted;      /* +0x6c */
    float fallDuration; /* +0x70 */
    u8 unknown74[0x2c];
    int direct;       /* +0xa0 */
    float weights[6]; /* +0xa4 */
};

/* derived name: the value clamped to [low, high], the bound returned by
 * reference (the addresses are selected, then loaded) */
template <typename T>
static inline const T &clampRef(const T &value, const T &low, const T &high) /* derived name */
{
    return value < low ? low : (value < high ? value : high);
}

/* derived name: the value of the time: itself while the flag at +0xa0 is
 * set, else its smooth step */
static inline float valueOf(const Object0145a4d0 *self) /* derived name */
{
    return self->direct ? self->time : easeSmooth(self->time);
}

/* derived names: slot 3 of the vtable at 0x16d63d8: a smooth-step fade that
 * rises while the control fades in and the owner's state is not 1 and its
 * three flags are clear, restarted on the control's restart, the owner's
 * state 1 or its status flag at +0x130; falling, the time is one less the
 * least of six weights while the flag at +0xa0 is set (and the value is the
 * time), else it falls by the step over the length at +0x70. The class is
 * not traced. */
void FUN_0145a4d0(Object0145a4d0 *self) /* derived name */
{
    int rising = self->control->direction == 1;
    if (self->owner->control->state == 1 || self->owner->control->flag1c ||
        self->owner->status->flag5e0)
        rising = 0;
    if (self->control->restart || self->owner->control->state == 1 ||
        self->owner->status->flag130) {
        self->control->state = 0;
        self->value = 0.0f;
        self->time = 0.0f;
    }
    self->restarted = self->control->state == 0 && rising;
    if (rising)
        self->time += self->control->step / self->duration;
    else if (self->direct) {
        float least = 1.0f;
        for (int i = 0; i < 6; i++)
            if (self->weights[i] < least)
                least = self->weights[i];
        self->time = 1.0f - least;
    } else
        self->time -= self->control->step / self->fallDuration;
    self->time = clampRef(self->time, 0.0f, 1.0f);
    self->value = valueOf(self);
    if (rising)
        self->control->state = 1;
    else
        self->control->state = self->value > 1e-8f ? 2 : 0;
}
