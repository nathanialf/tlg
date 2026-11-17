/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"

/* derived names: four floats eased toward a target over a time step at a
 * damping of 0.975 a sixtieth of a second: the share of the value kept is
 * 1 - 0.975 for each whole sixtieth of the step, then made smaller in
 * proportion for the part of a sixtieth left; the value becomes that share
 * of itself plus the rest of the target (the caller at 0x118f4f3 passes the
 * frame's step, +0x14 of the record at +0x10). */
// NONMATCHING: the SLP vectorizer's tree: the base multiplies the target's lanes alone and
// gathers them (`vinsertps`, lane 3 taken from the scaled value by `vblendps`, the target's own
// product put in the other vector), the build loads the target as one vector
void FUN_01190fd0(Float4A *value, const Float4 *target, float step) /* derived name */
{
    const float frame = 1.0f / 60.0f;
    const float damping = 0.975f;
    float kept = 1.0f;
    while (step > frame) {
        kept *= 1.0f - damping;
        step -= frame;
    }
    kept -= damping * (step / frame) * kept;
    const float rest = 1.0f - kept;
    *value = Float4A(value->x * kept + target->x * rest, value->y * kept + target->y * rest,
                     value->z * kept + target->z * rest, value->w * kept + target->w * rest);
}
