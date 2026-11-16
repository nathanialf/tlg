/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_vector00fdab40.h"

/* derived names: FUN_00fbcff0's walk (leaf_00fbcff0.cpp) over a vector:
 * moves a value toward a target at 60 frames a second, the whole frames of
 * the step one at a time and the fraction left as a part of one, by a rate
 * read from the eleven-entry table D_15251c0 at a speed clamped to 0..10;
 * the value is set to the target when their squared distance is under
 * 1e-10 squared (the constant is the float product, 0x1e3ce509, not
 * 1e-20f's 0x1e3ce508). The difference is taken again before the count is tested, so the
 * last one taken serves the fraction. Eleven other units hold a copy of
 * these bytes over their own constants (0x1047230, 0x10c3330, 0x10d49b0,
 * 0x113e290, 0x114d8d0, 0x1166800, 0x11e4dd0, 0x128e2b0, 0x12cf1a0,
 * 0x12e0820, 0x12ebf00), each called only from its own unit. */
extern const float D_15251c0[11]; /* derived: the rates by speed */

void FUN_00fdab40(Vector4Loop *value, const Vector4Loop &target, float speed,
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
