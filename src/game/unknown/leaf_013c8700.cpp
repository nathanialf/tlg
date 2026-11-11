/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: adds the 64-bit count at +0x98 of its argument times 8 to the 64-bit total at 0x40 and counts one at 0xf8, when the
 * amount is not zero; slot 96 of the vtable at 0x16d2818 (its pointer at 0x16d2b28);
 * the other slots of that vtable keep the same pairs of totals and counts. The
 * record types are not traced. Class and method unknown. */
struct Record013c8700 { /* derived name */
    u8 unknown0[0x98];
    u64 unknown98;
};

struct Object013c8700 { /* derived name */
    u8 unknown0[0x40];
    u64 unknown40;
    u8 unknown48[0xb0];
    u64 unknownf8;
};

void FUN_013c8700(Object013c8700 *self, const Record013c8700 *record) /* derived name */
{
    u64 size = record->unknown98 * 8;
    if (size) {
        self->unknown40 += size;
        ++self->unknownf8;
    }
}
