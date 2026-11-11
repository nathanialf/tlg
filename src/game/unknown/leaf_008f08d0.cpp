/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 6 of the vtables at 0x16b06b0 and 0x16b8db8: the pointer
 * at +0x88 of the record at +0x38 when it is set, else the one at +0x80. Class
 * and method unknown. */
struct Record008f08d0 { /* derived name */
    u8 unknown0[0x80];
    void *unknown80;
    void *unknown88;
};

struct Object008f08d0 { /* derived name */
    u8 unknown0[0x38];
    Record008f08d0 *unknown38;
};

void *FUN_008f08d0(const Object008f08d0 *self) /* derived name */
{
    const Record008f08d0 *record = self->unknown38;
    return record->unknown88 ? record->unknown88 : record->unknown80;
}
