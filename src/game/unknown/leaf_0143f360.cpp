/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_fade013e7030.h"

using namespace fade013e7030;

/* derived names: the object at +0x230 of the owner of the class whose
 * vtable is at 0x16d5f68: two flags at +0x778 and +0x780. The rest is not
 * traced. */
struct State0143f360 { /* derived name */
    u8 unknown0[0x778];
    int flag778; /* +0x778 */
    u8 unknown77c[0x4];
    int flag780; /* +0x780 */
};

struct Owner0143f360 { /* derived name */
    u8 unknown0[0x230];
    State0143f360 *state; /* +0x230 */
};

/* derived names: Object013e7030's fields with the owner above and two
 * flags of its own at +0x84 and +0x200 */
struct Object0143f360 { /* derived name */
    u8 unknown0[0x8];
    Owner0143f360 *owner;         /* +0x8 */
    FadeControl013e7030 *control; /* +0x10 */
    u8 unknown18[0x48];
    float value;    /* +0x60 */
    float time;     /* +0x64 */
    float duration; /* +0x68 */
    int restarted;  /* +0x6c */
    u8 unknown70[0x14];
    int flag84; /* +0x84 */
    u8 unknown88[0x178];
    int flag200; /* +0x200 */
};

/* derived name: the smooth step, 0 below 0 and 1 above 1 */
static inline float easeSmooth(float x) /* derived name */
{
    if (x < 0.0f)
        return 0.0f;
    if (x > 1.0f)
        return 1.0f;
    return x * x * (3.0f - 2.0f * x);
}

/* derived names: slot 3 of the vtable at 0x16d5f68: a fade whose direction
 * is whether the object's flag at +0x200 and the owner's state at +0x778 are
 * set with either the owner's +0x780 or the object's +0x84: then the time
 * rises by six steps, else it falls by the step over the length; the value
 * is the smooth step of the time clamped to [0, 1]. The direction is an
 * if with both arms (the true arm's empty block is folded into the merge's
 * phi first, so the false arm, which the last test reaches too, stays one
 * block: `mov al, 1; jne` and the three false edges into one `xor eax,
 * eax`). The class is not traced. */
void FUN_0143f360(Object0143f360 *self) /* derived name */
{
    if (self->control->restart) {
        self->control->state = 0;
        self->value = 0.0f;
        self->time = 0.0f;
    }
    bool rising;
    if (self->flag200 && self->owner->state->flag778 &&
        (self->owner->state->flag780 || self->flag84))
        rising = true;
    else
        rising = false;
    self->restarted = self->control->state == 0 && rising;
    if (rising)
        self->time += self->control->step * 6.0f;
    else
        self->time -= self->control->step / self->duration;
    self->time = clamp(self->time, 0.0f, 1.0f);
    self->value = easeSmooth(self->time);
    if (rising)
        self->control->state = 1;
    else
        self->control->state = self->value > 1e-8f ? 2 : 0;
}
