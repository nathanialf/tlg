/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_fade013e7030.h"

using namespace fade013e7030;

/* derived names: Object013e7030's fields with a flag of its own at +0x70
 * that lets the fade rise */
struct Object014176d0 { /* derived name */
    u8 unknown0[0x10];
    FadeControl013e7030 *control; /* +0x10 */
    u8 unknown18[0x48];
    float value;    /* +0x60 */
    float time;     /* +0x64 */
    float duration; /* +0x68 */
    int restarted;  /* +0x6c */
    int enabled;    /* +0x70 */
};

/* derived names: slot 3 of the vtable at 0x16d5b60: the sine fade of
 * FUN_013e7030 (leaf_013e7030.cpp) rising only while the flag at +0x70 is
 * set, the time stepped only while it is within [0, 1], then clamped. The
 * class is not traced. */
// NONMATCHING: the direction and the clamp's registers (408 bytes, base
// 412): the base compares the direction before the flag's test and keeps a
// branch (`sete cl; cmp [rbx+0x70], 0; je; movzx r14d, cl`, an int phi);
// here the two are one `and` of bytes (SimplifyCFG's select of the two
// entries, then InstCombine), and the clamp's zero is shared where the base
// clears xmm2 again. Lead: what keeps the phi of the zero-extended compare
// from being folded into a select (FoldTwoEntryPHINode's conditions) with
// the compare above the branch.
void FUN_014176d0(Object014176d0 *self) /* derived name */
{
    if (self->control->restart) {
        self->control->state = 0;
        self->value = 0.0f;
        self->time = 0.0f;
    }
    int rising = self->control->direction == 1;
    if (!self->enabled)
        rising = 0;
    self->restarted = self->control->state == 0 && rising ? 1 : self->restarted;
    float time = self->time;
    if (time >= 0.0f && time <= 1.0f) {
        const float step = self->control->step / self->duration;
        time = time + (rising ? step : -step);
    }
    self->time = clamp(time, 0.0f, 1.0f);
    const float t = self->time;
    if (t < 0.5f)
        self->value = easeInSine(t * 2.0f) * 0.5f;
    else
        self->value = easeOutSine((t - 0.5f) * 2.0f) * 0.5f + 0.5f;
    if (rising)
        self->control->state = 1;
    else
        self->control->state = self->value > 1e-8f ? 2 : 0;
}
