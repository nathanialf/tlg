/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 4 of the vtable at 0x16bd3b0 (its pointer at
 * 0x16bd3e0; stored by FUN_00b981a0 and FUN_00df0f40, home
 * ComputeInterface.cpp), beside FUN_00df2fe0: looks its last argument up
 * through FUN_00bafb90 on the object the pointer at 0x5835fb0 holds and
 * returns, through its first three, the found record's pointer at +0x40 and
 * that object's values at +0x2c8 and +0x2d8; returns 1. The object itself is
 * not read. The types are not traced. */
struct Object00df2f80; /* derived name */

struct Object05835fb0 { /* derived name */
    u8 unknown0[0x2c8];
    void *unknown2c8;
    u8 unknown2d0[8];
    void *unknown2d8;
};

struct Record00df2f80 { /* derived name */
    u8 unknown0[0x40];
    void *unknown40;
};

extern Object05835fb0 *D_5835fb0;

Record00df2f80 *FUN_00bafb90(Object05835fb0 *object, void *key); /* derived name */

int FUN_00df2f80(Object00df2f80 *, void **first, void **second, void **third,
                 void *key) /* derived name */
{
    Record00df2f80 *record = FUN_00bafb90(D_5835fb0, key);
    void *found = record->unknown40;
    void *value2c8 = D_5835fb0->unknown2c8;
    void *value2d8 = D_5835fb0->unknown2d8;
    *first = found;
    *second = value2c8;
    *third = value2d8;
    return 1;
}
