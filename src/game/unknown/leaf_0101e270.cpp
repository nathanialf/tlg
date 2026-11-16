/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_vector00fdab40.h"

/* derived names: FUN_00fdab40's walk (leaf_00fdab40.cpp) at a fixed rate of
 * 0.23 a frame: moves a vector toward a target at 60 frames a second, the
 * whole frames of the step one at a time and the fraction left as a part of
 * one; the value is set to the target when their squared distance is under
 * 1e-10 squared. Two other units hold these bytes at their own rates
 * (0x11b13d0 at 0.04, 0x12a7830 at 1 - 0.865), each called only from its
 * own unit. */
void FUN_0101e270(Vector4Loop *value, const Vector4Loop &target, float step) /* derived name */
{
    const float rate = 0.23f;
    Vector4Loop d = target - *value;
    if (dot(d, d) >= 1e-10f * 1e-10f) {
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
