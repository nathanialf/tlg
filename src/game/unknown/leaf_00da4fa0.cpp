/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: copies the int at +0xe88 to +0xc44 of the record the pointer
 * at +0x7dc8 holds; slot 130 of the vtable at 0x16bb0c0 (its pointer at
 * 0x16bb4e0), the vtable stored by FUN_00da4250 FUN_00ddbb60 | home
 * BytecodeReader.cpp. Class and method unknown. */
struct Record00da4fa0 { /* derived name */
    u8 unknown0[0xc44];
    int unknownc44;
    u8 unknownc48[0xe88 - 0xc48];
    int unknowne88;
};

struct Object00da4fa0 { /* derived name */
    u8 unknown0[0x7dc8];
    Record00da4fa0 *unknown7dc8;
};

void FUN_00da4fa0(Object00da4fa0 *self) /* derived name */
{
    self->unknown7dc8->unknownc44 = self->unknown7dc8->unknowne88;
}
