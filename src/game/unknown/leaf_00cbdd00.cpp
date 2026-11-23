/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_math.h"

/* derived names: a holder of points (w 1) at +0x248, each kept once */
struct Points00cbdd00 { /* derived name */
    u8 unknown0[0x248];
    Array05943280<Float4A> points; /* +0x248 */
};

/* derived name: the magnitude of a difference */
static inline float distance00cbdd00(float a, float b) /* derived name */
{
    const float d = a - b;
    return d > 0.0f ? d : -d;
}

/* derived names: the index of the point within 1e-5 of the given one on
 * each axis, or of the point appended (w 1) where none is (called by
 * FUN_00cbdf90) */
// NONMATCHING: the empty array's path: the base gives the new index as 0
// there (`xor ebx, ebx` at 0xcbddd6, the count known 0 on the guard's edge),
// the build keeps the count it read (`mov rcx, rbx`, the guard `test rbx,
// rbx`): the guard's edge into the append is critical when GVN runs, so the
// equality is not propagated (the unit's IR after LICM: the append's own
// load of the count in the block both exits reach)
unsigned FUN_00cbdd00(Points00cbdd00 *self, const Float4 &point) /* derived name */
{
    for (unsigned i = 0; i < self->points.size(); ++i) {
        const Float4A &p = self->points.at(i);
        if (distance00cbdd00(p.x, point.x) < 1e-5f && distance00cbdd00(p.y, point.y) < 1e-5f &&
            distance00cbdd00(p.z, point.z) < 1e-5f)
            return i;
    }
    return self->points.add(Float4A(point.x, point.y, point.z, 1.0f));
}
