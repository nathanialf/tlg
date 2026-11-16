/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_types.h"

#include <algorithm>

/* derived names: slot 3 of the vtable at 0x16d4d98 (its word at 0x16d4db0;
 * slots 0 and 1 0x13e8390 and 0x13e84b0): a sine ease in and out of the
 * object's time at +0x64 over its length at +0x68, stepped by the control's
 * step, its value at +0x60; one of 22 byte-identical slots of the classes at
 * 0x16d4xxx to 0x16d7xxx (0x13e90a0, 0x13effa0, ... 0x14941f0). The classes
 * are not traced. */
struct FadeControl013e7030 { /* derived name */
    int direction;           /* +0x0: 1 fading in */
    int state;               /* +0x4 */
    int restart;             /* +0x8 */
    u8 unknownc[0x8];
    float step; /* +0x14 */
};

struct Object013e7030 { /* derived name */
    u8 unknown0[0x10];
    FadeControl013e7030 *control; /* +0x10 */
    u8 unknown18[0x48];
    float value;    /* +0x60 */
    float time;     /* +0x64 */
    float duration; /* +0x68 */
    int restarted;  /* +0x6c */
};

static inline float easeInSine(float x) /* derived name */
{
    if (x <= 0.0f)
        return 0.0f;
    if (x >= 1.0f)
        return 1.0f;
    return 1.0f - sin((1.0f - x) * 1.57079637f);
}

static inline float easeOutSine(float x) /* derived name */
{
    if (x <= 0.0f)
        return 0.0f;
    if (x >= 1.0f)
        return 1.0f;
    return sin(x * 1.57079637f);
}

// NONMATCHING: std::min(1.0f, time): the base loads the chosen address's float
// (`cmovb rax, rcx; vmovss xmm1, [rax]`) and goes on with it; the build's load
// has the store as its only user and becomes an integer move (`mov ecx, [rcx];
// vmovd`), and the time below 0 is not threaded into the ease-in's tests as the
// base does; 21/91. Forms that use the value (a returned assignment, a local,
// a ternary) let the load be speculated (vminss or a constant 1 store).
// Round 348E, two-stage: this form still keeps the select (the 1.0's slot is
// stored in the else block, the base's before the `< 0` test). A clamp taking
// the value by reference and its bounds by value (`if (value < low) return
// low; return std::min(high, value);`, or the conditional form) is speculated
// inside the clamp (the reference argument is dereferenceable(4)): vminss; a
// local 1.0 in a conditional of lvalues is speculated likewise.
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
    float delta = self->control->step / self->duration;
    if (self->control->direction != 1)
        delta = -delta;
    self->time += delta;
    if (self->time < 0.0f)
        self->time = 0.0f;
    else
        self->time = std::min(1.0f, self->time);
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
