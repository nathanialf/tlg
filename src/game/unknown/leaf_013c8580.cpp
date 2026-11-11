/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 85 of the vtable at 0x16d2818 (its pointer at 0x16d2ac0;
 * and two more pointers): unless the top bit of the 64-bit word at +0x8 of its
 * argument is set, adds the word's low 62 bits plus 27 to the 64-bit total at
 * 0x38 and counts one at 0xf0, as the vtable's other slots keep their pairs of
 * totals and counts (FUN_013c8540). The record types are not traced. Class and
 * method unknown. */
struct Record013c8580 { /* derived name */
    u8 unknown0[8];
    u64 unknown8 : 62;
    u64 unknown8_62 : 1;
    u64 unknown8_63 : 1;
};

struct Object013c8580 { /* derived name */
    u8 unknown0[0x38];
    u64 unknown38;
    u8 unknown40[0xb0];
    u64 unknownf0;
};

void FUN_013c8580(Object013c8580 *self, const Record013c8580 *record) /* derived name */
{
    if (!record->unknown8_63) {
        self->unknown38 += record->unknown8 + 27;
        ++self->unknownf0;
    }
}
