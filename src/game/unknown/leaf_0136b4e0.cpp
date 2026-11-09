/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the pointer at +0x3c0 is set, as an int (the
 * bool widened, movzbl); slot 22 of the vtable at 0x16acb20 (its pointer at
 * 0x16acbe0), the vtable stored by FUN_007658a0 FUN_007659d0; slot 22 of the
 * vtable at 0x16adac0 (its pointer at 0x16adb80), the vtable stored by
 * FUN_0079dac0 FUN_0079dbc0. Class and method unknown. */
struct Object0136b4e0 { /* derived name */
    u8 unknown0[0x3c0];
    void *unknown3c0; /* type not traced */
};

int FUN_0136b4e0(const Object0136b4e0 *self) /* derived name */
{
    return self->unknown3c0 != 0;
}
