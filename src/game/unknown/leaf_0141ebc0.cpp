/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_fade013e7030.h"

/* derived names: the object at +0x460 of the owner of the class whose
 * vtable is at 0x16d5d08: two weights read at +0x1d90 and +0x1dc8. The rest
 * is not traced. */
struct Part0141ebc0 { /* derived name */
    u8 unknown0[0x1d90];
    float weight1d90; /* +0x1d90 */
    u8 unknown1d94[0x34];
    float weight1dc8; /* +0x1dc8 */
};

struct Owner0141ebc0 { /* derived name */
    u8 unknown0[0x460];
    Part0141ebc0 *part; /* +0x460 */
};

/* derived names: the fields slot 2 of the class whose vtable is at 0x16d5d08
 * reads and writes: the owner at +0x8, the control at +0x10 (its step), two
 * and seven weights through the pointers at +0x140 and +0x160, the value at
 * +0x1c0 and whether it is at 1 at +0x1c4. The class is not traced. */
struct Object0141ebc0 { /* derived name */
    u8 unknown0[0x8];
    Owner0141ebc0 *owner;         /* +0x8 */
    FadeControl013e7030 *control; /* +0x10 */
    u8 unknown18[0x128];
    float *weights140; /* +0x140: two */
    u8 unknown148[0x18];
    float *weights160; /* +0x160: seven */
    u8 unknown168[0x58];
    float value; /* +0x1c0 */
    int full;    /* +0x1c4 */
};

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
    else if (self->value > 1.0f)
        value = 1.0f;
    else {
        value = self->value + self->control->step * 0.5f;
        value = value < 1.0f ? value : 1.0f;
    }
    self->value = value;
    self->full = fabsf(self->value - 1.0f) <= 1e-5f;
}
