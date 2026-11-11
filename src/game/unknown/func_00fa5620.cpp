/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_math.h"
#include <functional>
#include <xmmintrin.h>

/* derived names: FUN_00fa5620 builds one std::function on the heap (the
 * 0x28-byte implementation, operator new at 0xfa5cfc; its vtable 0x16c0130,
 * the `lea` at 0xfa5d45) from a lambda holding three points by reference:
 * r15, the pointer argument kept in r13 and the local at rsp+0x170 (the
 * stores at 0xfa5d5a to 0xfa5d62). The lambda (0xfbdbd0) takes the plane of
 * the three points: the normal is the cross product of the second edge
 * (third point less the first) with the first (second point less the
 * first), scaled to unit length by one Newton step of the reciprocal square
 * root estimate (the constants -0.5 and -3 at 0x14db860 and 0x14db864) when
 * its squared length exceeds 1e-5 squared (0x14db85c holds the negated
 * product), and returns the point at +0x10 of its argument moved along it,
 * the argument's w kept. The returned Float4A travels through the hidden
 * pointer (its copy constructor is user-provided); the base loads all four
 * of the point's fields before its first store, as a constructor's
 * arguments are. The rest of the creating
 * function is not traced. */
struct Contact00fbdbd0 { /* derived name */
    u8 unknown0[0x10];
    Float4 unknown10; /* +0x10 */
};

typedef std::function<Float4A(const Contact00fbdbd0 &)> Offset00fa5620; /* derived name */

void FUN_013df660(const Offset00fa5620 &offset); /* derived name: its other arguments not traced */

static const float EPSILON = 1e-5f; /* derived name */

// NONMATCHING: not written beyond the lambda. Slot 2 (0xfbdbd0): every
// instruction the base's but their order and registers; the base adds the
// squares as (x + z) + y with x on the left, where Reassociate's ranks put z
// on the left here (the third point's z is the last load). Slots 0 and 1:
// the closure copied tail first (the parked 0x18-byte class).
void FUN_00fa5620(const Float4A &first, const Float4A &second) /* derived name */
{
    Float4A third;
    FUN_013df660(Offset00fa5620([&first, &second, &third](const Contact00fbdbd0 &contact) {
        float vx = second.x - first.x;
        float vy = second.y - first.y;
        float vz = second.z - first.z;
        float ux = third.x - first.x;
        float uy = third.y - first.y;
        float uz = third.z - first.z;
        float nx = uy * vz - uz * vy;
        float ny = uz * vx - ux * vz;
        float nz = ux * vy - uy * vx;
        float lengthSquared = nx * nx + nz * nz + ny * ny;
        float scale = 0.0f;
        if (lengthSquared - EPSILON * EPSILON > 0.0f) {
            float estimate = _mm_cvtss_f32(_mm_rsqrt_ss(_mm_set_ss(lengthSquared)));
            scale = estimate * -0.5f * (estimate * estimate * lengthSquared - 3.0f);
        }
        return Float4A(nx * scale + contact.unknown10.x, ny * scale + contact.unknown10.y,
                       nz * scale + contact.unknown10.z, contact.unknown10.w);
    }));
}
