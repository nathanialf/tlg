/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_types.h"

#include <algorithm>

/* derived names: a point of a link: three coordinates and a fourth word
 * each operation keeps from its left operand (the base copies it as an
 * integer, `mov eax, [rax+rcx+0xc]` into +0x2c) */
struct Point01401530 { /* derived name */
    float x, y, z, w;
};

inline Point01401530 operator-(const Point01401530 &a, const Point01401530 &b)
{
    Point01401530 r = a;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

inline Point01401530 operator+(const Point01401530 &a, const Point01401530 &b)
{
    Point01401530 r = a;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}

inline Point01401530 operator*(const Point01401530 &a, float s)
{
    Point01401530 r = a;
    r.x = a.x * s;
    r.y = a.y * s;
    r.z = a.z * s;
    return r;
}

/* derived names: the 0x50-byte link the track pulls: its two ends at +0x0
 * and +0x20 */
struct Link01401530 {    /* derived name */
    Point01401530 first; /* +0x0 */
    u8 unknown10[0x10];
    Point01401530 second; /* +0x20 */
    u8 unknown30[0x20];
};

/* derived names: the fields slot 4 of Object016d56b0 reads: the links at
 * +0xa8, the current one's index at +0xc4, a scale at +0xc8 and the
 * shortest, longest and softness factors at +0x114, +0x118 and +0x11c */
struct Object01401530 { /* derived name */
    u8 unknown0[0xa8];
    Link01401530 *links; /* +0xa8 */
    u8 unknownb0[0x14];
    int current; /* +0xc4 */
    float scale; /* +0xc8 */
    u8 unknowncc[0x48];
    float shortest; /* +0x114 */
    float longest;  /* +0x118 */
    float softness; /* +0x11c */
};

/* derived name: a cubic Hermite ease of a distance in two pieces, up to 2.9
 * and from 2.9 to 10, 0.99999 beyond */
static inline float ease01401530(float x)
{
    if (x >= 10.0f)
        return 0.99999f;
    float t, p0, p1, m0, m1;
    if (x < 2.9f) {
        t = x * 0.344828f;
        p0 = 0.0f;
        p1 = 0.76543f;
        m0 = 1.414347f;
        m1 = 0.3402686f;
    } else {
        t = (x - 2.9f) * 0.140845f;
        p0 = 0.76543f;
        p1 = 0.993262f;
        m0 = 0.8330714f;
        m1 = 0.0245305f;
    }
    const float t2 = t * t;
    const float t3 = t2 * t;
    return (2.0f * t3 - 3.0f * t2 + 1.0f) * p0 + (t3 - 2.0f * t2 + t) * m0 +
           (3.0f * t2 - 2.0f * t3) * p1 + (t3 - t2) * m1;
}

static inline float copySign01401530(float value, float sign)
{
    union {
        float f;
        u32 i;
    } v, s;

    v.f = value;
    s.f = sign;
    v.i = (v.i & 0x7fffffffu) | (s.i >> 31) << 31;
    return v.f;
}

/* derived names: slot 4 of Object016d56b0 (vtable 0x16d56b0, constructed at
 * +0x8e0 by FUN_01078df0): the current link pulled toward a length, the
 * excess eased by the softness, then held between the shortest and the
 * longest. One of seven byte-identical slots (0x1411f00, 0x1419cc0,
 * 0x1432410, 0x1442590, 0x1454920, 0x1460300). The classes are not traced. */
// NONMATCHING: 2/231 single-file, 1140 bytes against 1224, a first form
// from the data model: the points as a struct of four floats copied whole are
// taken by SLP as vectors (`vmovq; vsubps`) where the base loads and
// subtracts each coordinate as a scalar from the link (`vmovss xmm14,
// [rax+rcx]`), and the base zeroes xmm12 first and keeps the longest bound
// on the stack. The ease's polynomial and the two bounds' order are not
// worked.
void FUN_01401530(Object01401530 *self, float length) /* derived name */
{
    Point01401530 direction = self->links[self->current].first - self->links[self->current].second;
    const float distance =
        sqrtf(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
    if (distance > 1e-10f)
        direction = direction * (1.0f / distance);
    const float shortest = self->scale * self->shortest;
    const float longest = std::max(length, self->scale * self->longest);
    float excess = distance - length;
    const float size = excess > 0.0f ? excess : -excess;
    if (size >= 0.0f && fabsf(size) > 1e-10f) {
        const float softness = self->scale * self->softness;
        float x = size;
        if (fabsf(softness) > 1e-10f)
            x /= softness;
        excess = copySign01401530(ease01401530(x) * softness, excess);
    }
    float pulled = excess + length;
    Link01401530 &link = self->links[self->current];
    const Point01401530 middle = (link.first + link.second) * 0.5f;
    self->links[self->current].first = middle + direction * (pulled * 0.5f);
    self->links[self->current].second = middle - direction * (pulled * 0.5f);
    if (pulled > longest) {
        Link01401530 &held = self->links[self->current];
        const Point01401530 centre = (held.first + held.second) * 0.5f;
        self->links[self->current].first = centre + direction * (longest * 0.5f);
        self->links[self->current].second = centre - direction * (longest * 0.5f);
    } else {
        const float least = std::min(length, shortest);
        if (pulled < least) {
            Link01401530 &held = self->links[self->current];
            const Point01401530 centre = (held.first + held.second) * 0.5f;
            self->links[self->current].first = centre + direction * (least * 0.5f);
            self->links[self->current].second = centre - direction * (least * 0.5f);
        }
    }
}
