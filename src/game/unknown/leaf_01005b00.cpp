/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the int at +0x0 of the record the pointer at
 * +0x8 holds equals the int its argument points to, as an int (the bool
 * widened, movzbl); slot 2 of the vtable at 0x16c0af0 (its pointer at
 * 0x16c0b10), the vtable stored by FUN_01005a80 FUN_01005ac0. The argument's
 * type is not traced. Class and method unknown. */
struct Record01005b00 { /* derived name */
    int unknown0;
};

struct Object01005b00 { /* derived name */
    u8 unknown0[8];
    const Record01005b00 *unknown8;
};

int FUN_01005b00(const Object01005b00 *self, const int *value) /* derived name */
{
    return self->unknown8->unknown0 == *value;
}
