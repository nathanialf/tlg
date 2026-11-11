/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 80 of the vtable at 0x16bb0c0 (its pointer at
 * 0x16bb350): passes the object and the record at +0x16f0 of the object at
 * +0x7dc8 to FUN_00da7fc0 when the record's ints at +0x38 and +0x3c are
 * equal, else to FUN_00da8700, as a tail call. Class and method unknown. */
struct Record00daaac0 { /* derived name */
    u8 unknown0[0x38];
    int unknown38;
    int unknown3c;
};

struct Member00daaac0 { /* derived name */
    u8 unknown0[0x16f0];
    Record00daaac0 *unknown16f0;
};

struct Object00daaac0 { /* derived name */
    u8 unknown0[0x7dc8];
    Member00daaac0 *unknown7dc8;
};

void FUN_00da7fc0(Object00daaac0 *self, Record00daaac0 *record); /* derived name */
void FUN_00da8700(Object00daaac0 *self, Record00daaac0 *record); /* derived name */

void FUN_00daaac0(Object00daaac0 *self) /* derived name */
{
    Record00daaac0 *record = self->unknown7dc8->unknown16f0;
    if (record->unknown38 == record->unknown3c) {
        FUN_00da7fc0(self, record);
    } else {
        FUN_00da8700(self, record);
    }
}
