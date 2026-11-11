/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 7 of the vtable at 0x16b9048 (its pointer at
 * 0x16b9090): 0 when the record at +0x40 exists and its ints at +0x50 and
 * +0x30 are both set; else the int at +0x50 of the record at +0x38. Class and
 * method unknown. */
struct Record00cb3d20 { /* derived name */
    u8 unknown0[0x30];
    int unknown30;
    u8 unknown34[0x1c];
    int unknown50;
};

struct Object00cb3d20 { /* derived name */
    u8 unknown0[0x38];
    Record00cb3d20 *unknown38;
    Record00cb3d20 *unknown40;
};

int FUN_00cb3d20(const Object00cb3d20 *self) /* derived name */
{
    const Record00cb3d20 *record = self->unknown40;
    if (record && record->unknown50 != 0 && record->unknown30 != 0) {
        return 0;
    }
    return self->unknown38->unknown50;
}
