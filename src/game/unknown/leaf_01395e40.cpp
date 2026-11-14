/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16cf2b0 (+0x50 from the vtable stored at
 * 0x16cf260): when the record at +0x5b0 of the record at +0x10 of its argument
 * is present, sets that record's float at +0x5c to 1 when the object's int at
 * 0xd8 is nonzero, else 0; returns 1. The classes and the return type are not
 * traced. */
struct Record01395e40 { /* derived name */
    u8 unknown0[0x5c];
    float unknown5c;
};

struct Holder01395e40 { /* derived name */
    u8 unknown0[0x5b0];
    Record01395e40 *unknown5b0;
};

struct Argument01395e40 { /* derived name */
    u8 unknown0[0x10];
    Holder01395e40 *unknown10;
};

struct Object01395e40 { /* derived name */
    u8 unknown0[0xd8];
    int unknownd8;
};

int FUN_01395e40(Object01395e40 *self, Argument01395e40 *argument) /* derived name */
{
    Record01395e40 *record = argument->unknown10->unknown5b0;
    if (record != 0) {
        record->unknown5c = self->unknownd8 != 0;
    }
    return 1;
}
