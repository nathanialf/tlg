/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores the value in the int at +0xfc of each of the
 * record's 0x100-byte entries (the array at +0x50, counted by the unsigned
 * int at +0x58) whose flags byte at +0xe4 has bit 0 set; the store may alias
 * the array and its count, so both are read again after it. The types are
 * not traced. Class and method unknown. */
struct Entry00968a60 { /* derived name */
    u8 unknown0[0xe4];
    u8 unknowne4; /* +0xe4: bit 0 tested */
    u8 unknowne5[0x17];
    int unknownfc; /* +0xfc */
};

struct Object00968a60 { /* derived name */
    u8 unknown0[0x50];
    Entry00968a60 *unknown50; /* +0x50 */
    u32 unknown58;            /* +0x58: the entry count */
};

void FUN_00968a60(Object00968a60 *self, int value) /* derived name */
{
    for (u32 i = 0; i < self->unknown58; i++) {
        if (self->unknown50[i].unknowne4 & 1)
            self->unknown50[i].unknownfc = value;
    }
}
