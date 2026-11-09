/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores 1 in the 16-bit field at +0xe of the record the
 * pointer at +0x1798 of the record the pointer at +0x7dc8 holds points to;
 * slot 33 of the vtable at 0x16bb0c0 (its pointer at 0x16bb1d8); FUN_00daff10
 * reaches the same record. Class and method unknown. */
struct Record00daf300 { /* derived name */
    u8 unknown0[0xe];
    u16 unknowne;
};

struct Owner00daf300 { /* derived name */
    u8 unknown0[0x1798];
    Record00daf300 *unknown1798;
};

struct Object00daf300 { /* derived name */
    u8 unknown0[0x7dc8];
    Owner00daf300 *unknown7dc8;
};

void FUN_00daf300(Object00daf300 *self) /* derived name */
{
    self->unknown7dc8->unknown1798->unknowne = 1;
}
