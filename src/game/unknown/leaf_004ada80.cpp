/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: where a value lies between two bounds, 0 at or below the
 * lower and 1 at or above the upper, linear between; bounds given in the
 * other order give the mirrored step (one less the step over the bounds
 * swapped, the function calling itself); one half when the bounds are equal.
 * Its callers are not traced. */
float FUN_004ada80(float value, float from, float to) /* derived name */
{
    if (from <= to) {
        float step = 0.0f;
        if (value > from) {
            if (value >= to) {
                step = 1.0f;
            } else {
                float range = to - from;
                step = range > 0.0f ? (value - from) / range : 0.5f;
            }
        }
        return step;
    }
    return 1.0f - FUN_004ada80(value, to, from);
}
