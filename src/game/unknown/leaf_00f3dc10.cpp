/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 8 of the vtable at 0x16bf1b8: when the record at +0x220
 * is set, stores 16 less bit 1 of its word at +0x100 at its +0x48; returns 0.
 * Class and method unknown. */
struct Record00f3dc10 { /* derived name */
    u8 unknown0[0x48];
    int unknown48;
    u8 unknown4c[0xb4];
    u32 unknown100;
};

struct Object00f3dc10 { /* derived name */
    u8 unknown0[0x220];
    Record00f3dc10 *unknown220;
};

int FUN_00f3dc10(Object00f3dc10 *self) /* derived name */
{
    if (Record00f3dc10 *record = self->unknown220) {
        record->unknown48 = 16 - ((record->unknown100 >> 1) & 1);
    }
    return 0;
}
