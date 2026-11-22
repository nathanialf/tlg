/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <float.h>

/* derived names: the curve FUN_00f54a00 hands FUN_00f54500 (float (float,
 * float, float), called at 0xf54686 with the value and FUN_00f54a00's two
 * floats). Below the start the value's distance from it is taken as a
 * share of the range (1 for an empty range) and mapped through a cubic
 * Hermite curve in two pieces (shares under 2.9, and 2.9 to 10; 0.99999 from
 * 10 on), the result put back on the range from the start. Above the start
 * it is 0, at the start the start itself. Meaning unknown. */
// NONMATCHING: the value at the start: the base returns it through a branch to FLT_MAX
// (`vucomiss FLT_MAX; jb`, its return shared with the 0 past the start), the build a `vminss`
// (the two arms speculated into a select); the empty range's test is then laid out the other
// way and the curve's sum ordered apart (309 against 306 bytes)
float FUN_00f54a10(float value, float end, float start) /* derived name */
{
    if (value > start)
        return 0.0f;
    if (value >= start) {
        if (value < FLT_MAX)
            return value;
        return FLT_MAX;
    }
    float range = end - start;
    float share = range == 0.0f ? 1.0f : (value - start) / range;
    float curve;
    if (share >= 10.0f) {
        curve = 0.99999f;
    } else {
        float t, p0, m0, p1, m1;
        if (share >= 2.9f) {
            t = (share - 2.9f) * 0.140845f;
            p0 = 0.76543f;
            m0 = 0.8330714f;
            p1 = 0.993262f;
            m1 = 0.0245305f;
        } else {
            t = share * 0.344828f;
            p0 = 0.0f;
            m0 = 1.4143474f;
            p1 = 0.76543f;
            m1 = 0.3402686f;
        }
        float t2 = t * t;
        float t3 = t2 * t;
        curve = (2.0f * t3 - 3.0f * t2 + 1.0f) * p0 + (t3 - 2.0f * t2 + t) * m0 +
                (3.0f * t2 - 2.0f * t3) * p1 + (t3 - t2) * m1;
    }
    return curve * range + start;
}
