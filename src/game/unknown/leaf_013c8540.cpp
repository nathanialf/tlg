/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: adds the 64-bit size at +0x0 of its argument in units of 1024
 * (shifted right by 10) to the 64-bit total at 0x18 and counts one at 0xd0,
 * when the argument is not null and the amount is not zero; slot 81 of the
 * vtable at 0x16d2818 (its pointer at 0x16d2ab0); the other slots of that
 * vtable keep the same pairs of totals and counts. The record types are not
 * traced. Class and method unknown. */
struct Record013c8540 { /* derived name */
    u64 unknown0;
};

struct Object013c8540 { /* derived name */
    u8 unknown0[0x18];
    u64 unknown18;
    u8 unknown20[0xb0];
    u64 unknownd0;
};

void FUN_013c8540(Object013c8540 *self, const Record013c8540 *record) /* derived name */
{
    if (record) {
        u64 size = record->unknown0 >> 10;
        if (size) {
            self->unknown18 += size;
            ++self->unknownd0;
        }
    }
}
