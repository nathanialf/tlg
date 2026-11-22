/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d3ef8.h"
#include "tlg_types.h"
#include <xmmintrin.h>

/* derived names: slot 2 of the vtable at 0x16d42c0 (its pointer at
 * 0x16d42d0): the base's slot 2 (FUN_013dfda0, tlg_game_object016d3ef8.h)
 * first, the two vectors at +0x70 cleared one by one (stored as one 32-byte
 * store); then the
 * position and rotation of the target's first entry computed from the
 * model's pose of the first index unless the entry's int at +0x90 says they
 * are, the position copied to +0x90 and the int at +0xe0 set. The same
 * body as FUN_013e27f0 and FUN_013e2650 but for the clearing. Class and
 * method unknown. */
struct Pair013e27f0 { /* derived name */
    Vec4 unknown0;    /* +0x0 */
    Vec4 unknown10;   /* +0x10 */
};

struct Object013e27f0 : Object016d3ef8 { /* derived name */
    Pair013e27f0 unknown70;              /* +0x70 */
    Vec4 unknown90;                      /* +0x90: the first entry's position */
    u8 unknowna0[0x40];
    int unknowne0; /* +0xe0 */
};

// NONMATCHING: GVN's PRE of the position's address: the build keeps `&entry.unknown50` in a
// register across the branch (formed again in the skip path, `add rbx, 0x50`); the base forms it
// before the call and reads [entry + 0x50] after the join. Naming the position before the branch
// keeps the address live from the test instead.
void FUN_013e27f0(Object013e27f0 *self) /* derived name */
{
    self->Object016d3ef8::slot2();
    self->unknown70.unknown0 = _mm_setzero_ps();
    self->unknown70.unknown10 = _mm_setzero_ps();
    FadeTarget013d2490 *target = self->owner->target;
    FadeTargetEntry013d2490 &entry = target->entries[0];
    if (!entry.unknown90) {
        const int index = target->unknown28[0];
        FadeModel013d4610 *model = self->model;
        FUN_013ce2d0(&model->skeleton, &entry.unknown50, index, model->skeleton.poses);
        FUN_013ce660(&model->skeleton, &entry.unknown60, index, model->skeleton.poses);
        entry.unknown90 = 1;
    }
    self->unknown90 = entry.unknown50;
    self->unknowne0 = 1;
}
