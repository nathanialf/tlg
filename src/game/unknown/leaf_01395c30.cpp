/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16cf348 (+0xe8 from the vtable stored at
 * 0x16cf260): when the record at +0x5b0 of the record at +0x10 of its argument
 * is present, sets that record's float at +0x5c to 1 when the object's int at
 * 0xa0 is nonzero, else 0; returns 1. The classes and the return type are not
 * traced. */
struct Record01395c30 { /* derived name */
    u8 unknown0[0x5c];
    float unknown5c;
};

struct Holder01395c30 { /* derived name */
    u8 unknown0[0x5b0];
    Record01395c30 *unknown5b0;
};

struct Argument01395c30 { /* derived name */
    u8 unknown0[0x10];
    Holder01395c30 *unknown10;
};

struct Object01395c30 { /* derived name */
    u8 unknown0[0xa0];
    int unknowna0;
};

int FUN_01395c30(Object01395c30 *self, Argument01395c30 *argument) /* derived name */
{
    Record01395c30 *record = argument->unknown10->unknown5b0;
    if (record != 0) {
        record->unknown5c = self->unknowna0 != 0;
    }
    return 1;
}
