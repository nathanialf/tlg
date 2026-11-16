/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_vector00fdab40.h"

/* derived names: a copy of FUN_00fdab40 (leaf_00fdab40.cpp, where the walk
 * is described) over its own unit's constants: moves a vector toward a
 * target at 60 frames a second by a rate read from the eleven-entry table
 * D_15251c0 at a speed clamped to 0..10. Called only from its own unit. */
extern const float D_15251c0[11]; /* derived: the rates by speed */

void FUN_010c3330(Vector4Loop *value, const Vector4Loop &target, float speed,
                  float step) /* derived name */
{
    Vector4Loop d = target - *value;
    if (dot(d, d) >= 1e-10f * 1e-10f) {
        speed = speed < 0.0f ? 0.0f : (speed < 10.0f ? speed : 10.0f);
        unsigned index = (unsigned)speed;
        if (index == 10)
            index = 9;
        float part = speed - (float)index;
        float rate = (1.0f - part) * D_15251c0[index] + part * D_15251c0[index + 1];
        float frames = step * 59.999996f;
        int whole = (int)frames;
        float fraction = frames - (float)whole;
        for (;;) {
            d = target - *value;
            if (!(whole-- > 0))
                break;
            *value = rate * d + *value;
        }
        *value = fraction * rate * d + *value;
    } else {
        *value = target;
    }
}
