/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <float.h>

/* derived names: the curve FUN_00f54a00 hands FUN_00f54500 (float (float,
 * float, float), called at 0xf54686 with the value and FUN_00f54a00's two
 * floats). Below the start the value's distance from it is taken as a
 * share of the range (1 for an empty range) and mapped through a cubic
 * Hermite curve in two pieces (shares under 2.9, and 2.9 to 10; 0.99999 from
 * 10 on), the result put back on the range from the start. Above the start
 * it is 0, at the start the start itself (no more than FLT_MAX). Each piece
 * is the curve from p0 to p1 with the tangents m0 and m1, summed as the
 * points' part and the tangents' part. Meaning unknown. The same function
 * is at 0xf6ed30, 0xfbd9f0, 0x10160e0, 0x1215600, 0x12274a0 and 0x124bd50
 * (leaf_00f6ed30.cpp and the others, generated from this file). */
float FUN_00f54a10(float value, float end, float start) /* derived name */
{
    float result;
    if (value > start) {
        result = 0.0f;
    } else if (value < start) {
        float range = end - start;
        float share = range != 0.0f ? (value - start) / range : 1.0f;
        float curve;
        if (share >= 10.0f) {
            curve = 0.99999f;
        } else {
            float t, p0, p1, m0, m1;
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
            float points = (2.0f * t3 - 3.0f * t2 + 1.0f) * p0 + t2 * (3.0f - 2.0f * t) * p1;
            float tangents = (t3 - 2.0f * t2 + t) * m0 + (t3 - t2) * m1;
            curve = points + tangents;
        }
        result = curve * range + start;
    } else {
        result = value;
        if (result >= FLT_MAX)
            result = FLT_MAX;
    }
    return result;
}
