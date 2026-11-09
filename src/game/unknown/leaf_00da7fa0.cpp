/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00da7fc0 with the object and the pointer at +0x16f0
 * of the record the pointer at +0x7dc8 holds, as a tail call. The types and
 * the return type are not traced; slot 75 of the vtable at 0x16bb0c0 (its
 * pointer at 0x16bb328), the vtable stored by FUN_00da4250 FUN_00ddbb60 | home
 * BytecodeReader.cpp. Class and method unknown. */
struct Target00da7fa0; /* derived name */

struct Record00da7fa0 { /* derived name */
    u8 unknown0[0x16f0];
    Target00da7fa0 *unknown16f0;
};

struct Object00da7fa0 { /* derived name */
    u8 unknown0[0x7dc8];
    Record00da7fa0 *unknown7dc8;
};

void FUN_00da7fc0(Object00da7fa0 *self, Target00da7fa0 *target); /* derived name */

void FUN_00da7fa0(Object00da7fa0 *self) /* derived name */
{
    FUN_00da7fc0(self, self->unknown7dc8->unknown16f0);
}
