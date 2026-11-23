/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_math.h"

/* derived name: where a triangle's outline crosses a plane, the two points
 * of the cut (FUN_00f4dbe0's result) */
struct Cut00f4dbe0 { /* derived name */
    Float4 from;
    Float4 to;

    Cut00f4dbe0(const Float4A &from_, const Float4A &to_)
        : from(from_.x, from_.y, from_.z, from_.w), to(to_.x, to_.y, to_.z, to_.w)
    {
    }
};

/* derived name: the dot product of two vectors' x, y and z */
static inline float dot(const Float4 &a, const Float4 &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

/* derived names: where the edge from start to end crosses the plane through
 * point with the unit normal: the ends' signed distances from the plane
 * (under 1e-5 taken as on it), no crossing when both are on it or they are
 * on the same side, otherwise the point between them at the distances'
 * ratio, its w the end's. The executable has it at 0xf52d40 with the
 * three vectors passed as their nine floats: the link's argument promotion
 * of this static (its callers are FUN_00f4dbe0 and FUN_00f40940). */
// NONMATCHING: 56/74 at the base's 303 bytes: the base loads end.x first (before the start's distance is
// summed) and end.z last, ours end.z first; the registers of the end's lanes follow
static int crossing(Float4A &hit, const Float4 &end, const Float4 &point, const Float4 &normal,
                    const Float4 &start) /* derived name */
{
    const float offset = dot(point, normal);
    const Float4 onPlane(offset * normal.x, offset * normal.y, offset * normal.z, 0.0f);
    float fromStart =
        dot(Float4(onPlane.x - start.x, onPlane.y - start.y, onPlane.z - start.z, 0.0f), normal);
    float fromEnd =
        dot(Float4(onPlane.x - end.x, onPlane.y - end.y, onPlane.z - end.z, 0.0f), normal);
    if (fabsf(fromStart) < 1e-5f)
        fromStart = 0.0f;
    if (fabsf(fromEnd) < 1e-5f)
        fromEnd = 0.0f;
    if (fromEnd == 0.0f && fromStart == 0.0f)
        return 0;
    if ((fromStart >= 0.0f && fromEnd <= 0.0f) || (fromStart <= 0.0f && fromEnd >= 0.0f)) {
        const float share = fabsf(fromStart) / (fabsf(fromEnd) + fabsf(fromStart));
        hit = Float4A((end.x - start.x) * share + start.x, (end.y - start.y) * share + start.y,
                      (end.z - start.z) * share + start.z, end.w);
        return 1;
    }
    return 0;
}

/* derived names: the cut of a triangle (three corners) by the plane through
 * point with the unit normal: each edge's crossing (the third not tried when
 * the first two cross), gathered in order into a cleared array, and the cut
 * when exactly two cross; 0 otherwise.
 * Called by FUN_00f4de30 (three times); the same function is at 0x1210b70. */
// NONMATCHING: 94/141, 579 against 581 bytes: the count of hits in ecx where the base has eax, so the
// return's 0 is materialised before `cmp ecx, 2` where the base gives it a block of its own
int FUN_00f4dbe0(Cut00f4dbe0 &cut, const Float4 *corners, const Float4 &normal,
                 const Float4 &point) /* derived name */
{
    const Float4 &a = corners[0];
    const Float4 &b = corners[1];
    const Float4 &c = corners[2];
    Float4A hit0(0.0f, 0.0f, 0.0f, 0.0f);
    Float4A hit1(0.0f, 0.0f, 0.0f, 0.0f);
    Float4A hit2(0.0f, 0.0f, 0.0f, 0.0f);
    Float4A hits[3];
    int crossed = 0;
    if (crossing(hit0, b, point, normal, a))
        crossed |= 1;
    if (crossing(hit1, c, point, normal, b))
        crossed |= 2;
    if (crossed != 3 && crossing(hit2, a, point, normal, c))
        crossed |= 4;
    if (crossed == 0)
        return 0;
    memset(hits, 0, sizeof(hits));
    unsigned count = 0;
    if (crossed & 1)
        hits[count++] = hit0;
    if (crossed & 2)
        hits[count++] = hit1;
    if (crossed & 4)
        hits[count++] = hit2;
    if (count != 2)
        return 0;
    cut = Cut00f4dbe0(hits[0], hits[1]);
    return 1;
}
