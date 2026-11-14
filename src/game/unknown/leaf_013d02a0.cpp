/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 5 of the vtables at 0x16d3798, 0x16d3c08 and 0x16d6960:
 * the int at +0x50 of the entry the index selects in the 144-byte entries the
 * record at +0x8 points to at +0x18, or 0 when the index is not below the
 * record's count at +0x20. Class and method unknown. */
struct Entry013d02a0 { /* derived name */
    u8 unknown0[0x50];
    int unknown50;
    u8 unknown54[0x3c];
};

struct Record013d02a0 { /* derived name */
    u8 unknown0[0x18];
    Entry013d02a0 *unknown18;
    u32 unknown20;
};

struct Object013d02a0 { /* derived name */
    u8 unknown0[0x8];
    Record013d02a0 *unknown8;
};

int FUN_013d02a0(const Object013d02a0 *self, int index) /* derived name */
{
    const Record013d02a0 *record = self->unknown8;
    if (index < record->unknown20) {
        return record->unknown18[index].unknown50;
    }
    return 0;
}
