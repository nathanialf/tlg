/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: whether an address lies in the range the record the pointer
 * at +0x38 holds describes, its start the pointer at +0x18 and its length the
 * 64-bit value at +0x360 (false when the record is null); slot 7 of the vtable
 * at 0x16b8bb0 (its pointer at 0x16b8bf8), stored by FUN_001bd010,
 * FUN_001db8b0, FUN_00783b40, FUN_00949e10, FUN_009c3230 and FUN_00a8b610. The
 * record's other fields are not traced. */
struct Record00ca1e60 { /* derived name */
    u8 unknown0[0x18];
    const u8 *unknown18;
    u8 unknown20[0x340];
    u64 unknown360;
};

struct Object00ca1e60 { /* derived name */
    u8 unknown0[0x38];
    Record00ca1e60 *unknown38;
};

int FUN_00ca1e60(const Object00ca1e60 *self, const u8 *address) /* derived name */
{
    bool inside = false;
    const Record00ca1e60 *record = self->unknown38;
    if (record && record->unknown18 < address)
        inside = address < record->unknown18 + record->unknown360;
    return inside;
}
