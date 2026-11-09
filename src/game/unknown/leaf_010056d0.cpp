/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the int at +0x4 of the record the pointer at
 * +0x8 holds differs from the int its argument points to, as an int (the bool
 * widened, movzbl); slot 2 of the vtable at 0x16c09b0 (its pointer at
 * 0x16c09d0), the vtable stored by FUN_01005650 FUN_01005690. The argument's
 * type is not traced. Class and method unknown. */
struct Record010056d0 { /* derived name */
    u8 unknown0[4];
    int unknown4;
};

struct Object010056d0 { /* derived name */
    u8 unknown0[8];
    const Record010056d0 *unknown8;
};

int FUN_010056d0(const Object010056d0 *self, const int *value) /* derived name */
{
    return self->unknown8->unknown4 != *value;
}
