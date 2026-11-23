/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_vector00fdab40.h"

extern const float D_1524a00[16]; /* the factors by time (leaf_00fdadf0.cpp) */

/* derived names: a copy of FUN_00fdaa20 (leaf_00fdaa20.cpp, where the step
 * over a vector and the order of its operations are described) over its own
 * unit's constants (15, 1 and 13, the same values). Called from 6 sites in 2 functions (FUN_0141f490, FUN_0142c5b0). */
void FUN_0113f910(Vector4Loop *value, Vector4Loop *previous, const Vector4Loop &target, float time,
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
    float stiffness = rate * rate;
    Vector4Loop current = *value;
    Vector4Loop delta = current - *previous;
    *value = factor * (stiffness * ((target - current - delta) * (13.0f / rate)) + delta) + current;
    *previous = current;
}
