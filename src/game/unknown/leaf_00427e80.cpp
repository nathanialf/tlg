/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <float.h>

#include "tlg_game_name.h"
#include "tlg_game_value004af700.h"

/* derived name: the point the object starts from (no file defines it yet) */
extern Value004af700 D_57d4500;

/* derived names: the class whose vtable is at 0x16a98a8 (stored by
 * FUN_004233f0 FUN_00427cc0) as slot 9 sees it: three names, the
 * distances kept with them and a point */
struct Object00427e80 { /* derived name */
    u8 unknown0[0x110];
    Name unknown110;
    float unknown114; /* +0x114 */
    Name unknown118;
    u8 unknown11c[4];
    Value004af700 unknown120; /* +0x120 */
    float unknown130;         /* +0x130 */
    float unknown134;         /* +0x134 */
    float unknown138;         /* +0x138 */
    float unknown13c;         /* +0x13c */
    float unknown140;         /* +0x140 */
    float unknown144;         /* +0x144 */
    Name unknown148;
    int unknown14c; /* +0x14c */
    int unknown150; /* +0x150 */
};

/* derived names: slot 9 of the vtable at 0x16a98a8: the object reset, its
 * three names released, its distances made the largest float, its point
 * the one at 0x57d4500, the int at +0x14c -1 and the one after it 0. */
// NONMATCHING: 57/60, 294 bytes against 297: the base stores the two distances at +0x130 and
// +0x134 as two dword immediates; the build merges them into one 8-byte store (`movabs rax,
// 0x7f7fffff7f7fffff`; DAGCombiner's MergeConsecutiveStores). The point is Value004af700's
// member-by-member copy (two 8-byte loads split), equal.
void FUN_00427e80(Object00427e80 *self) /* derived name */
{
    self->unknown110.release();
    self->unknown114 = FLT_MAX;
    self->unknown118.release();
    self->unknown130 = FLT_MAX;
    self->unknown134 = FLT_MAX;
    self->unknown120.set(D_57d4500);
    self->unknown138 = FLT_MAX;
    self->unknown13c = FLT_MAX;
    self->unknown140 = 0.0f;
    self->unknown144 = 0.0f;
    self->unknown148.release();
    self->unknown14c = -1;
    self->unknown150 = 0;
}
