/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 16 of the vtable at 0x16b1208 (stored by FUN_00961bf0
 * FUN_00967d40 FUN_00967e80; its pointer at 0x16b1298): sets or clears bit 3
 * of the flags at +0xe4 of each of the object's 0x100-byte entries (the array
 * at +0x50, counted by the unsigned int at +0x58, as slot 21, FUN_009687e0,
 * walks them) by its bool argument. Class and method unknown. */
struct Entry009685a0 { /* derived name */
    u8 unknown0[0xe4];
    u32 flagse4; /* +0xe4 */
    u8 unknowne8[0x18];
};

struct Object009685a0 { /* derived name */
    u8 unknown0[0x50];
    Entry009685a0 *unknown50; /* +0x50 */
    u32 unknown58;            /* +0x58: the entry count */
};

void FUN_009685a0(Object009685a0 *self, bool enable) /* derived name */
{
    for (u32 i = 0; i < self->unknown58; i++) {
        Entry009685a0 &entry = self->unknown50[i];
        if (enable)
            entry.flagse4 |= 8;
        else
            entry.flagse4 &= ~8;
    }
}
