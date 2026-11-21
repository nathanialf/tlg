/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: moves a value toward a target by 0.08 of the distance per
 * frame at 60 frames a second (the constant 59.999996), the whole frames
 * of the step one at a time and the fraction left as a part of one; the value
 * is set to the target when the two are closer than 1e-10. Called three
 * times, from 0x1057848 to 0x105788b; FUN_0101e320 (leaf_0101e320.cpp) has
 * the same bytes over its own constants (0.11 of the distance). */
void FUN_01063f20(float *value, float target, float step) /* derived name */
{
    float distance = target - *value > 0.0f ? target - *value : *value - target;
    if (distance >= 1e-10f) {
        float frames = step * 59.999996f;
        int whole = (int)frames;
        float fraction = frames - (float)whole;
        while (whole-- > 0)
            *value = *value + (target - *value) * 0.08f;
        *value = *value + fraction * 0.08f * (target - *value);
    } else {
        *value = target;
    }
}
