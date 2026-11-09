/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_013bde50 with the address of the field at +0x1708
 * of the record the pointer at +0x7dc8 holds, as a tail call. The field's type
 * and the return type are not traced; slot 26 of the vtable at 0x16bb0c0 (its
 * pointer at 0x16bb1a0), the vtable stored by FUN_00da4250 FUN_00ddbb60 | home
 * BytecodeReader.cpp. Class and method unknown. */
struct Record00daf400 { /* derived name */
    u8 unknown0[0x1708];
    u8 unknown1708; /* type not traced; its address is passed */
};

struct Object00daf400 { /* derived name */
    u8 unknown0[0x7dc8];
    Record00daf400 *unknown7dc8;
};

void FUN_013bde50(void *field); /* derived name */

void FUN_00daf400(Object00daf400 *self) /* derived name */
{
    FUN_013bde50(&self->unknown7dc8->unknown1708);
}
