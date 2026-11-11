/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"
#include "tlg_types.h"

/* derived names: a virtual method (its address at 0x16aa120, 0x16aa190 and
 * 0x16aa2e0 in .data.rel.ro) that returns the position at +0x40 moved by 0.2
 * of the vector at 0x57d78a0 (its fourth component kept), by value through
 * the hidden pointer (Float4, tlg_math.h). Class and method unknown. */
struct Vec3057d78a0 { /* derived name */
    float x;
    float y;
    float z;
};

extern Vec3057d78a0 D_57d78a0;

struct Object004b00a0 { /* derived name */
    u8 unknown0[0x40];
    Float4 position; /* +0x40, derived name */
};

// NONMATCHING: list-ilp order: the base computes x, y, z in that order into xmm1, xmm2,
// xmm0; the build schedules the z product first (xmm1) and x last (also with the offset
// as a Vec3 product first); the loads before the stores and the w load first are the base's.
Float4 FUN_004b00a0(const Object004b00a0 *self) /* derived name */
{
    const float w = self->position.w;
    const float x = self->position.x + D_57d78a0.x * 0.2f;
    const float y = self->position.y + D_57d78a0.y * 0.2f;
    const float z = self->position.z + D_57d78a0.z * 0.2f;
    Float4 result;
    result.x = x;
    result.y = y;
    result.z = z;
    result.w = w;
    return result;
}
