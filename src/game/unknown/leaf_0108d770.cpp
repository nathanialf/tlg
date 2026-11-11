/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: one step of a smoothed value (called at 0x107f2f5): from the
 * value and its previous one, the step the target asks for less the current
 * velocity, over the time step, times the time step squared and 13, plus the
 * velocity, scaled by 0.44f and added to the value; the old value becomes the
 * previous one. FUN_0108d770 and FUN_0109ddf0 differ in the scale (0.44 and
 * 0.24). The meaning of the constants is not traced. */
// NONMATCHING: the two adds' operands are commuted: the base adds the velocity to the product (vaddss xmm0, xmm0, xmm3) and the value to the scaled sum (vaddss xmm0, xmm0, xmm2), the build the other way round; both source orders compile the same
void FUN_0108d770(float *value, float *previous, float target, float step) /* derived name */
{
    float current = *value;
    float velocity = current - *previous;
    float acceleration = (target - current - velocity) / step;
    *value = current + (velocity + step * step * 13.0f * acceleration) * 0.44f;
    *previous = current;
}
