/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"
#include "tlg_math.h"

/* derived name: a value clamped to [low, high] */
static inline float clamp00fdae80(float value, float low, float high)
{
    return value < low ? low : (value < high ? value : high);
}

/* derived name: the size of a value with the sign of another, by their
 * bits */
static inline float copySign00fdae80(float value, float sign)
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

/* derived name: a rotation about one axis (0 x, 1 y, 2 z) as a quaternion,
 * from the sine and the cosine of its angle: w the square root of
 * (1 + cos) / 2, the axis's lane that of (1 - cos) / 2 with the sine's sign
 * (the half angle's), the other lanes zero; the cosine clamped to [-1, 1].
 * Its callers (FUN_00fce150 and four more) pass _FSin's two results. */
// NONMATCHING: the schedule (17/44, 202 against 203 bytes): the base materialises the zero before the
// sums and runs both estimates before the stores, the second's Newton step split around them; the
// clamp (a helper: written inline the outer select stays a branch) and the sign by bits (movmskps;
// shl 31) are the base's
void FUN_00fdae80(Float4A &rotation, int axis, float sine, float cosine) /* derived name */
{
    const float half = clamp00fdae80(cosine, -1.0f, 1.0f) * 0.5f;
    const float w = 0.5f + half;
    const float v = 0.5f - half;
    const float cosHalf = sqrtf(w < 0.0f ? 0.0f : w);
    const float sinHalf = sqrtf(v < 0.0f ? 0.0f : v);
    rotation.w = cosHalf;
    rotation.z = 0.0f;
    rotation.y = 0.0f;
    rotation.x = 0.0f;
    (&rotation.x)[axis] = copySign00fdae80(sinHalf, sine);
}
