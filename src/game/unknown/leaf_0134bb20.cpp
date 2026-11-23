/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_math.h"

/* derived name: a rotation quaternion's axis (w 1) and its angle in
 * degrees: twice the arc cosine of w, clamped to [-1, 1]; the axis is the
 * vector part over sqrt(1 - w * w), or the quaternion itself when that is
 * 1e-5 or less. Nineteen callers (FUN_003128f0 to the 0x1200000s). */
float FUN_0134bb20(const Float4A &rotation, Float4A &axis) /* derived name */
{
    const float w = rotation.w;
    const float half = acosf(w < -1.0f ? -1.0f : (w < 1.0f ? w : 1.0f));
    const float length = sqrtf(1.0f - w * w);
    if (length > 1e-5f) {
        const float scale = 1.0f / length;
        axis =
            Float4A(rotation.x * scale, rotation.y * scale, rotation.z * scale, rotation.w * scale);
    } else {
        axis = rotation;
    }
    axis.w = 1.0f;
    return half * (2.0f * 180.0f / 3.14159265f);
}
