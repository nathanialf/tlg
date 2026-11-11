/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_simd.h"

/* derived names: slot 10 of the vtable at 0x16b6c20 (its pointer at
 * 0x16b6c80): copies the vectors at +0x120 and +0x140 of the record at +0x28,
 * when there is one, to +0x40 and +0x50. Class and method unknown. */
struct Record00b77050 { /* derived name */
    u8 unknown0[0x120];
    Vec4 unknown120;
    u8 unknown130[0x10];
    Vec4 unknown140;
};

struct Object00b77050 { /* derived name */
    u8 unknown0[0x28];
    Record00b77050 *unknown28;
    u8 unknown30[0x10];
    Vec4 unknown40;
    Vec4 unknown50;
};

void FUN_00b77050(Object00b77050 *self) /* derived name */
{
    Record00b77050 *record = self->unknown28;
    if (record) {
        self->unknown40 = record->unknown120;
        self->unknown50 = record->unknown140;
    }
}
