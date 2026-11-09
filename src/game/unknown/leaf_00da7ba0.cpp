/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00da7bc0 with the object, its second argument and
 * the pointer at +0x16f0 of the record the pointer at +0x7dc8 holds, as a tail
 * call. The types and the return type are not traced; slot 76 of the vtable at
 * 0x16bb0c0 (its pointer at 0x16bb330), the vtable stored by FUN_00da4250
 * FUN_00ddbb60 | home BytecodeReader.cpp. Class and method unknown. */
struct Target00da7ba0; /* derived name */

struct Record00da7ba0 { /* derived name */
    u8 unknown0[0x16f0];
    Target00da7ba0 *unknown16f0;
};

struct Object00da7ba0 { /* derived name */
    u8 unknown0[0x7dc8];
    Record00da7ba0 *unknown7dc8;
};

void FUN_00da7bc0(Object00da7ba0 *self, void *argument, Target00da7ba0 *target); /* derived name */

void FUN_00da7ba0(Object00da7ba0 *self, void *argument) /* derived name */
{
    FUN_00da7bc0(self, argument, self->unknown7dc8->unknown16f0);
}
