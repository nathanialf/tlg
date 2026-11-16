/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* A table of 16 floats, 0.12 rising by 0.04 to 0.72 (read by eight functions
 * of the same body, 0xfdadf0 to 0x1280560). */
extern const float D_1524a00[16];

/* derived names: one step of a value toward a target. The time is clamped to
 * [0, 15] and picks a factor from the table by linear interpolation between
 * two entries (the last pair at 14); the value's change since the previous
 * step is kept, and the new value and the previous one are written back.
 * The order of the statements is the base's: the factor before the value is
 * read (the value's load numbered after the clamp's, `vmovss xmm5, [rdi]`
 * against the minimum in xmm3) and before the pull (Reassociate ranks a load
 * and a division by their place in the block: the sum then outranks the
 * factor, `vmulss xmm0, xmm0, xmm1`), the entry below first in the factor. */
void FUN_00fdadf0(float *value, float *previous, float target, float time, float rate)
{
    float clamped = time < 15.0f ? time : 15.0f;
    if (time < 0.0f)
        clamped = 0.0f;
    unsigned index = (unsigned)clamped;
    if (index == 15)
        index = 14;
    float fraction = clamped - (float)index;
    float factor = D_1524a00[index] * (1.0f - fraction) + D_1524a00[index + 1] * fraction;
    float current = *value;
    float delta = current - *previous;
    float pull = (target - current - delta) / rate;
    *value = (rate * rate * 13.0f * pull + delta) * factor + current;
    *previous = current;
}
