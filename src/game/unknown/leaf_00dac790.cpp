/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears the int the pointer at +0x16f0 of the record the
 * pointer at +0x7dc8 holds points to; slot 83 of the vtable at 0x16bb0c0 (its
 * pointer at 0x16bb368). Class and method unknown. */
struct Owner00dac790 { /* derived name */
    u8 unknown0[0x16f0];
    int *unknown16f0;
};

struct Object00dac790 { /* derived name */
    u8 unknown0[0x7dc8];
    Owner00dac790 *unknown7dc8;
};

void FUN_00dac790(Object00dac790 *self) /* derived name */
{
    *self->unknown7dc8->unknown16f0 = 0;
}
