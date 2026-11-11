/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: when the pointer at +0x38 of the object is not null, passes
 * it, the pointer at 0x581b938 and 0 to FUN_00c57870; then clears the int at
 * +0x238; slot 11 of the vtable at 0x16ac098 (its pointer at 0x16ac100),
 * stored by FUN_006703a0. The types beyond the widths and the callee's return
 * type are not traced. */
struct Member00670920_38; /* derived name */

struct Object00670920 { /* derived name */
    u8 unknown0[0x38];
    Member00670920_38 *unknown38;
    u8 unknown40[0x1f8];
    int unknown238;
};

extern void *D_581b938;

void FUN_00c57870(Member00670920_38 *member, void *value, int flag); /* derived name */

void FUN_00670920(Object00670920 *self) /* derived name */
{
    if (self->unknown38)
        FUN_00c57870(self->unknown38, D_581b938, 0);
    self->unknown238 = 0;
}
