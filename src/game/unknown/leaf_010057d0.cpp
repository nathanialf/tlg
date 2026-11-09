/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the int at +0x0 of the record the pointer at
 * +0x8 holds differs from the int its argument points to, as an int (the bool
 * widened, movzbl); slot 2 of the vtable at 0x16c0a00 (its pointer at
 * 0x16c0a20), the vtable stored by FUN_01005750 FUN_01005790. The argument's
 * type is not traced. Class and method unknown. */
struct Record010057d0 { /* derived name */
    int unknown0;
};

struct Object010057d0 { /* derived name */
    u8 unknown0[8];
    const Record010057d0 *unknown8;
};

int FUN_010057d0(const Object010057d0 *self, const int *value) /* derived name */
{
    return self->unknown8->unknown0 != *value;
}
