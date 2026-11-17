/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016ac990.h"
#include "tlg_libc.h"

/* derived names: a rotation with its axis reversed (x, y and z negated, w
 * copied as it is) */
static inline Float4A conjugate(const Float4A &q) /* derived name */
{
    return Float4A(-q.x, -q.y, -q.z, q.w);
}

static const float EPSILON = 1e-5f; /* derived name */

/* derived names: a rotation scaled to unit length; the identity where its
 * squared length is no more than the epsilon squared (0x2edbe6fe, one ulp
 * under the float nearest 1e-10, as tlg_game_vector.h's). Under -ffast-math
 * the inverse length is the estimate and one Newton step (`vrsqrtss`, the
 * factors -0.5 and -3.0: LLVM 3.7's reciprocal square root estimate,
 * DAGCombiner::BuildRsqrtEstimate) */
static inline Float4A normalized(const Float4A &q) /* derived name */
{
    const float lengthSquared = q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w;
    if (lengthSquared > EPSILON * EPSILON) {
        const float scale = 1.0f / sqrtf(lengthSquared);
        return Float4A(q.x * scale, q.y * scale, q.z * scale, q.w * scale);
    }
    return Float4A(0.0f, 0.0f, 0.0f, 1.0f);
}

/* derived names: slot 14 of the vtable at 0x16ac990: the body at +0x68 put
 * back to its point and rotation; then, unless the body's int at +0x1330 is
 * set or nothing is held at +0x118, the body is turned and moved: by the
 * object held at +0x120 when there is one (its rotation turned back by the
 * rotation at +0x130 and made unit length, its point less the offset at
 * +0x140; the held object read again for the point), else by the pose */
void Object016ac990::slot14(Pose0077bac0 *pose)
{
    goHome();
    if (unknown68->unknown1330 || !held118.get())
        return;
    if (held120.get()) {
        Float4A turn;
        const Float4A back = conjugate(unknown130);
        turn = normalized(FUN_013439c0(back, held120.get()->rotation));
        const Float4A &point = held120.get()->position;
        const Vector0077bac0 offset(point.x - unknown140.x, point.y - unknown140.y,
                                    point.z - unknown140.z);
        unknown68->turn(turn);
        unknown68->move(offset);
    } else {
        follow(pose);
    }
}
