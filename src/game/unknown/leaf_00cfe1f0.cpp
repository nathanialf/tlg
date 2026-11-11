/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 5 of the vtable at 0x16b9c70 (its pointer at
 * 0x16b9ca8): whether the record at +0xc8 exists and its byte at +0x94 is set.
 * Class and method unknown. */
struct Record00cfe1f0 { /* derived name */
    u8 unknown0[0x94];
    u8 unknown94;
};

struct Object00cfe1f0 { /* derived name */
    u8 unknown0[0xc8];
    Record00cfe1f0 *unknownc8;
};

int FUN_00cfe1f0(const Object00cfe1f0 *self) /* derived name */
{
    const Record00cfe1f0 *record = self->unknownc8;
    return record && record->unknown94 != 0;
}
