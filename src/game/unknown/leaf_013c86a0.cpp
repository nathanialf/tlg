/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: adds the 64-bit size at +0x0 of its argument in units of 1024
 * (shifted right by 10), when the argument is not null, to the 64-bit total at 0x98 and counts one at 0x150, when the
 * amount is not zero; slot 89 of the vtable at 0x16d2818 (its pointer at 0x16d2af0);
 * the other slots of that vtable keep the same pairs of totals and counts. The
 * record types are not traced. Class and method unknown. */
struct Record013c86a0 { /* derived name */
    u64 unknown0;
};

struct Object013c86a0 { /* derived name */
    u8 unknown0[0x98];
    u64 unknown98;
    u8 unknowna0[0xb0];
    u64 unknown150;
};

void FUN_013c86a0(Object013c86a0 *self, const Record013c86a0 *record) /* derived name */
{
    if (record) {
        u64 size = record->unknown0 >> 10;
        if (size) {
            self->unknown98 += size;
            ++self->unknown150;
        }
    }
}
