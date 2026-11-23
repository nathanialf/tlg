/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_types.h"

/* derived name: the size of a value with the sign of another, by their
 * bits */
static inline float copySign00f548a0(float value, float sign)
{
    union {
        float f;
        u32 bits;
    } result, from;

    result.f = value;
    from.f = sign;
    result.bits = (result.bits & 0x7fffffff) | (from.bits & 0x80000000);
    return result.f;
}

/* derived names: FUN_00f54a10's curve over the value's size, the result
 * given the value's sign. Below the start it is 0; a size under the start
 * or not above 1e-10 is the value itself. Otherwise the size's distance from
 * the start is taken as a share of the range (when the range's size is
 * above 1e-10) and mapped through the same two Hermite pieces, the result put
 * back on the range from the start. Meaning unknown. The same function is
 * at 0xf6ebc0, 0xfbd880, 0x1015f70, 0x1215490, 0x1227330 and 0x124bbe0. */
// NONMATCHING: 344 against 352 bytes, every instruction the base's but the two value exits: the base's
// `vmovaps xmm3, xmm0; ret` (a dead copy into the result's register) where ours are a bare `ret`
// (MachineCopyPropagation erases the tail-duplicated copy pair, MachineCopyPropagation.cpp:151-181, 317-327)
float FUN_00f548a0(float value, float end, float start) /* derived name */
{
    float result;
    if (value < start) {
        result = 0.0f;
    } else {
        const float size = fabsf(value);
        if (size < start || size <= 1e-10f) {
            result = value;
        } else {
            const float over = size - start;
            const float range = end - start;
            const float share = (range > 0.0f ? range : -range) > 1e-10f ? over / range : over;
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
            result = copySign00f548a0(curve * range + start, value);
        }
    }
    return result;
}
