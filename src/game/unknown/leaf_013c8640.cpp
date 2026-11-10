/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: adds the 64-bit size at +0x0 of its argument in units of 1024
 * (shifted right by 10) to the 64-bit total at 0x58 and counts one at 0x110,
 * when the amount is not zero; slot 86 of the vtable at 0x16d2818 (its pointer
 * at 0x16d2ad8); the other slots of that vtable keep the same pairs of totals
 * and counts. The record types are not traced. Class and method unknown. */
struct Record013c8640 { /* derived name */
    u64 unknown0;
};

struct Object013c8640 { /* derived name */
    u8 unknown0[0x58];
    u64 unknown58;
    u8 unknown60[0xb0];
    u64 unknown110;
};

void FUN_013c8640(Object013c8640 *self, const Record013c8640 *record) /* derived name */
{
    u64 size = record->unknown0 >> 10;
    if (size) {
        self->unknown58 += size;
        ++self->unknown110;
    }
}
