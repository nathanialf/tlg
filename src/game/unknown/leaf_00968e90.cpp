/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 29 of the vtable at 0x16b1208 (stored by FUN_00961bf0
 * FUN_00967d40 FUN_00967e80; its pointer at 0x16b1300): for each of the
 * object's 0x100-byte entries (the array at +0x50, counted by the unsigned int
 * at +0x58, as FUN_00968550 walks them) with bit 1 of its flags at +0xe4 set
 * and a pointer at +0x40, passes that pointer to FUN_009598b0. Class and
 * method unknown; the pointer's type is not traced. */
struct Target00968e90; /* derived name */

struct Entry00968e90 { /* derived name */
    u8 unknown0[0x40];
    Target00968e90 *unknown40;
    u8 unknown48[0x9c];
    u32 flagse4; /* +0xe4 */
    u8 unknowne8[0x18];
};

struct Object00968e90 { /* derived name */
    u8 unknown0[0x50];
    Entry00968e90 *unknown50; /* +0x50 */
    u32 unknown58;            /* +0x58: the entry count */
};

void FUN_009598b0(Target00968e90 *target); /* derived name */

void FUN_00968e90(Object00968e90 *self) /* derived name */
{
    for (u32 i = 0; i < self->unknown58; i++) {
        Entry00968e90 &entry = self->unknown50[i];
        if ((entry.flagse4 & 2) && entry.unknown40)
            FUN_009598b0(entry.unknown40);
    }
}
