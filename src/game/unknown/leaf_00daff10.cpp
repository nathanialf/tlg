/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: copies the int at +0x14 to +0x8 of the record the pointer at
 * +0x1798 of the record the pointer at +0x7dc8 holds points to; slot 7 of the
 * vtable at 0x16bb0c0 (its pointer at 0x16bb108); FUN_00daf300 reaches the
 * same record. Class and method unknown. */
struct Record00daff10 { /* derived name */
    u8 unknown0[8];
    int unknown8;
    u8 unknownc[8];
    int unknown14;
};

struct Owner00daff10 { /* derived name */
    u8 unknown0[0x1798];
    Record00daff10 *unknown1798;
};

struct Object00daff10 { /* derived name */
    u8 unknown0[0x7dc8];
    Owner00daff10 *unknown7dc8;
};

void FUN_00daff10(Object00daff10 *self) /* derived name */
{
    Record00daff10 *record = self->unknown7dc8->unknown1798;
    record->unknown8 = record->unknown14;
}
