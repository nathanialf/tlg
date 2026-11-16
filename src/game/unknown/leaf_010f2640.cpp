/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

extern const float D_1524a00[16]; /* the factors by time (leaf_00fdadf0.cpp) */

/* derived names: a copy of FUN_00fdadf0 (leaf_00fdadf0.cpp, where the step
 * and the order of its statements are described) over its own unit's
 * constants (15, 1 and 13, the same values). Called from 4 sites in 1 function (FUN_010ddf10). */
void FUN_010f2640(float *value, float *previous, float target, float time,
                  float rate) /* derived name */
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
