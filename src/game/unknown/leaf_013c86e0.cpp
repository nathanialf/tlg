/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: adds the 64-bit count at +0x10 of its argument times 16 to
 * the 64-bit total at 0x40 and counts one at 0xf8, when the amount is not
 * zero; slot 92 of the vtable at 0x16d2818 (its pointer at 0x16d2b08); the
 * other slots of that vtable keep the same pairs of totals and counts. The
 * record types are not traced. Class and method unknown. */
struct Record013c86e0 { /* derived name */
    u8 unknown0[0x10];
    u64 unknown10;
};

struct Object013c86e0 { /* derived name */
    u8 unknown0[0x40];
    u64 unknown40;
    u8 unknown48[0xb0];
    u64 unknownf8;
};

void FUN_013c86e0(Object013c86e0 *self, const Record013c86e0 *record) /* derived name */
{
    u64 size = record->unknown10 * 16;
    if (size) {
        self->unknown40 += size;
        ++self->unknownf8;
    }
}
