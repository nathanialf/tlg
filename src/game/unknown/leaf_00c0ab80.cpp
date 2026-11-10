/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00c0a830 with the pointer at +0xf0 of the object
 * and the address of +0x88 of its argument, and returns 0; its address is
 * taken by FUN_00be6da0. The pointee types and FUN_00c0a830's return type are
 * not traced. Class and method unknown. */
struct Target00c0ab80; /* derived name */

struct Object00c0ab80 { /* derived name */
    u8 unknown0[0xf0];
    Target00c0ab80 *unknownf0;
};

struct Record00c0ab80 { /* derived name */
    u8 unknown0[0x88];
    u8 unknown88; /* derived name; its type is not traced */
};

void FUN_00c0a830(Target00c0ab80 *target, u8 *value); /* derived name */

int FUN_00c0ab80(Object00c0ab80 *self, Record00c0ab80 *record) /* derived name */
{
    FUN_00c0a830(self->unknownf0, &record->unknown88);
    return 0;
}
