/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_vector00fdab40.h"

/* A table of 16 floats, 0.12 rising by 0.04 to 0.72 (leaf_00fdadf0.cpp). */
extern const float D_1524a00[16];

/* derived names: FUN_00fdadf0's step of a value toward a target
 * (leaf_00fdadf0.cpp) over a vector: the factor read from the table at the
 * time clamped to [0, 15], the value's change since the previous step kept,
 * the new value and the previous one written back.
 * NONMATCHING: the base multiplies each lane by rate * rate and then by
 * 13 / rate (13 folded into the reciprocal); here 13 joins rate * rate
 * (Reassociate) and the reciprocal is 1 / rate: six source orders give the
 * same IR. Structure otherwise equal (58 instructions). */
void FUN_00fdaa20(Vector4Loop *value, Vector4Loop *previous, const Vector4Loop &target, float time,
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
    Vector4Loop current = *value;
    Vector4Loop delta = current - *previous;
    Vector4Loop pull = (target - current - delta) / rate;
    *value = factor * (rate * rate * 13.0f * pull + delta) + current;
    *previous = current;
}
