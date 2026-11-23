/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <float.h>

/* derived names: FUN_00f54a10's curve (leaf_00f54a10.cpp, whose text this is), the
 * copy at 0x1215600. Generated from that file. */
float FUN_01215600(float value, float end, float start) /* derived name */
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
