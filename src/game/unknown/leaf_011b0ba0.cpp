/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

extern const float D_15251c0[11]; /* derived: the rates by speed (leaf_00fbcff0.cpp) */

/* derived names: FUN_00fbcff0's walk toward a target (leaf_00fbcff0.cpp)
 * with the distance under which the value is set to the target an argument
 * instead of 1e-10, over its own unit's constants (10, 1 and 59.999996, the
 * same values). Called from 8 sites in 2 functions (FUN_0119aa00, FUN_011a7d40). */
void FUN_011b0ba0(float *value, float target, float speed, float step,
                  float threshold) /* derived name */
{
    float distance = target - *value > 0.0f ? target - *value : *value - target;
    if (distance >= threshold) {
        speed = speed < 0.0f ? 0.0f : (speed < 10.0f ? speed : 10.0f);
        unsigned index = (unsigned)speed;
        if (index == 10)
            index = 9;
        float part = speed - (float)index;
        float rate = (1.0f - part) * D_15251c0[index] + part * D_15251c0[index + 1];
        float frames = step * 59.999996f;
        int whole = (int)frames;
        float fraction = frames - (float)whole;
        while (whole-- > 0)
            *value = *value + (target - *value) * rate;
        *value = *value + fraction * rate * (target - *value);
    } else {
        *value = target;
    }
}
