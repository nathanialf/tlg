/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* A table of 16 floats, 0.12 rising by 0.04 to 0.72 (read by eight functions
 * of the same body, 0xfdadf0 to 0x1280560). */
extern const float D_1524a00[16];

/* derived names: one step of a value toward a target. The value's change
 * since the previous step is kept, the time is clamped to [0, 15] and picks
 * a factor from the table by linear interpolation between two entries (the
 * last pair at 14), and the new value and the previous one are written back. */
// NONMATCHING: instruction order (list-ilp): the base takes the minimum with 15 before the compare with 0; and the operand order of three commutative operations (the base: product + delta, sum * factor, result + current; the build: Reassociate by rank, the lower rank first)
void FUN_00fdadf0(float *value, float *previous, float target, float time, float rate)
{
    float current = *value;
    float delta = current - *previous;
    float clamped = time < 15.0f ? time : 15.0f;
    if (time < 0.0f)
        clamped = 0.0f;
    unsigned index = (unsigned)clamped;
    if (index == 15)
        index = 14;
    float fraction = clamped - (float)index;
    float pull = (target - current - delta) / rate;
    float factor = D_1524a00[index + 1] * fraction + D_1524a00[index] * (1.0f - fraction);
    *value = (rate * rate * 13.0f * pull + delta) * factor + current;
    *previous = current;
}
