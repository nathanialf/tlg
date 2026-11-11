/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: moves a value toward a target by 0.11 of the distance per
 * frame at 60 frames a second (the constant 59.999996), the whole frames
 * of the step one at a time and the fraction left as a part of one; nothing
 * is done when the two are closer than 1e-10. Called once, from 0x10198c8;
 * FUN_01063f20 (leaf_01063f20.cpp) has the same bytes over its own
 * constants. */
// NONMATCHING: a register exchange (the base's distance pair in xmm4/xmm5 the other way, the
// conversion's pass-through register xmm0 where the build takes xmm6) and both adds with the
// value as the second operand (`vaddss xmm2, xmm4, xmm2`), either spelling of the sum giving the first
void FUN_0101e320(float *value, float target, float step) /* derived name */
{
    float distance = target - *value > 0.0f ? target - *value : *value - target;
    if (distance >= 1e-10f) {
        float frames = step * 59.999996f;
        int whole = (int)frames;
        float fraction = frames - (float)whole;
        while (whole-- > 0)
            *value = *value + (target - *value) * 0.11f;
        *value = *value + fraction * 0.11f * (target - *value);
    }
}
