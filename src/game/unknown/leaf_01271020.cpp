/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the int at +0x0 of the record the pointer at
 * +0x8 holds equals the int its argument points to, as an int (the bool
 * widened, movzbl); slot 2 of the vtable at 0x16c2c90 (its pointer at
 * 0x16c2cb0), the vtable stored by FUN_01270fa0 FUN_01270fe0. The argument's
 * type is not traced. Class and method unknown. */
struct Record01271020 { /* derived name */
    int unknown0;
};

struct Object01271020 { /* derived name */
    u8 unknown0[8];
    const Record01271020 *unknown8;
};

int FUN_01271020(const Object01271020 *self, const int *value) /* derived name */
{
    return self->unknown8->unknown0 == *value;
}
