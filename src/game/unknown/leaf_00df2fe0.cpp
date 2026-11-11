/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: when the 64-bit value at +0x38 of the record the pointer at
 * +0x60 of its second argument holds is nonzero, passes the pointer at
 * 0x5835fb0 and that record to FUN_00b9ccb0; returns 1. Slot 5 of the vtable
 * at 0x16bd3b0 (its pointer at 0x16bd3e8), stored by FUN_00b981a0 and
 * FUN_00df0f40. The object itself is not read. The records' types and the
 * callee's return type are not traced. */
struct Object00df2fe0; /* derived name */
struct Object05835fb0; /* derived name */

struct Record00df2fe0_60 { /* derived name */
    u8 unknown0[0x38];
    void *unknown38;
};

struct Argument00df2fe0 { /* derived name */
    u8 unknown0[0x60];
    Record00df2fe0_60 *unknown60;
};

extern Object05835fb0 *D_5835fb0;

void FUN_00b9ccb0(Object05835fb0 *object, Record00df2fe0_60 *record); /* derived name */

int FUN_00df2fe0(Object00df2fe0 *, Argument00df2fe0 *argument) /* derived name */
{
    Record00df2fe0_60 *record = argument->unknown60;
    if (record->unknown38)
        FUN_00b9ccb0(D_5835fb0, record);
    return 1;
}
