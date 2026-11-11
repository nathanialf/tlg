/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 39 of the vtable at 0x16bb0c0 (the vtable of
 * FUN_00daf400's object): FUN_00daba60 on the object with its argument, the
 * 16-bit count at +0xe of the record at +0x1798 of the record at +0x7dc8
 * (taken, then raised by one), -1 and 0, as a tail call. The types are not
 * traced. Class and method unknown. */
struct Counter00daedd0 { /* derived name */
    u8 unknown0[0xe];
    u16 unknowne;
};

struct Record00daedd0 { /* derived name */
    u8 unknown0[0x1798];
    Counter00daedd0 *unknown1798;
};

struct Object00daedd0 { /* derived name */
    u8 unknown0[0x7dc8];
    Record00daedd0 *unknown7dc8;
};

void FUN_00daba60(Object00daedd0 *self, void *arg, u32 index, int a, int b); /* derived name */

void FUN_00daedd0(Object00daedd0 *self, void *arg) /* derived name */
{
    Counter00daedd0 *counter = self->unknown7dc8->unknown1798;
    FUN_00daba60(self, arg, counter->unknowne++, -1, 0);
}
