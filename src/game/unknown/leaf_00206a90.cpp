/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_math.h"
#include <xmmintrin.h>

/* derived names: a rotation of the given degrees about an axis as a
 * quaternion: the axis normalised by the estimated reciprocal square root
 * refined once (left zero when shorter than 1e-5, as func_00fa5620.cpp's
 * normal), times the sine of half the angle (pi / 360 a degree), the cosine
 * in w. */
static const float EPSILON = 1e-5f; /* derived name */

// NONMATCHING: the build spills x, y and z across the two _FSin calls and multiplies by the scale
// after them; the base multiplies first and spills the three products (an operation sunk past the
// calls; not resolved)
void FUN_00206a90(Float4A *rotation, float x, float y, float z, float degrees) /* derived name */
{
    float lengthSquared = x * x + y * y + z * z;
    float scale = 0.0f;
    if (lengthSquared - EPSILON * EPSILON > 0.0f) {
        float estimate = _mm_cvtss_f32(_mm_rsqrt_ss(_mm_set_ss(lengthSquared)));
        scale = estimate * -0.5f * (estimate * estimate * lengthSquared - 3.0f);
    }
    float ax = scale * x;
    float ay = scale * y;
    float az = scale * z;
    float half = degrees * (3.14159265f / 360.0f);
    float s = sinf(half);
    float c = cosf(half);
    rotation->x = s * ax;
    rotation->y = s * ay;
    rotation->z = s * az;
    rotation->w = c;
}
