/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"

/* derived names: point moved to the nearest point of the line through a and
 * b (a + (b - a) * t, t the projection of point - a on b - a over its
 * squared length), its w taken from b; point set to a when a and b are
 * closer than 1e-10 in every axis. Called four and more times in a row from
 * 0x103d1f0's neighbourhood. Eight other units hold a copy of these bytes
 * (0x108d650, 0x10f2450, 0x1100240, 0x113e080, 0x1166900, 0x11914d0,
 * 0x11b1710, 0x11ca600).
 * NONMATCHING: instruction order and commutative operand order only (65
 * instructions both): the base has (point - a) * (b - a) and (b - a) * t
 * where these give (b - a) * (point - a) and t * (b - a) (Reassociate's
 * ranks), and stores the w word before the products. Writing point - a
 * before b - a is what puts a.y and b.y in the entry block (GVN's PRE
 * inserts the loads in the order the general block reads them, and only
 * the same order is hoisted). */
void FUN_01047610(Float4A &point, const Float4A &a, const Float4A &b) /* derived name */
{
    if ((a.x - b.x > 0.0f ? a.x - b.x : b.x - a.x) < 1e-10f &&
        (a.y - b.y > 0.0f ? a.y - b.y : b.y - a.y) < 1e-10f &&
        (a.z - b.z > 0.0f ? a.z - b.z : b.z - a.z) < 1e-10f) {
        point = a;
        return;
    }
    Float4A v(point.x - a.x, point.y - a.y, point.z - a.z, point.w);
    Float4A d(b.x - a.x, b.y - a.y, b.z - a.z, b.w);
    float t = (d.x * v.x + d.y * v.y + d.z * v.z) / (d.x * d.x + d.y * d.y + d.z * d.z);
    point = Float4A(t * d.x, t * d.y, t * d.z, d.w);
    const float x = point.x + a.x;
    const float y = point.y + a.y;
    const float z = point.z + a.z;
    point.x = x;
    point.y = y;
    point.z = z;
}
