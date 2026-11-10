/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: adds the 32-bit count at +0x0 of its argument times 16 to the
 * 64-bit total at 0xc0 and counts one at 0x178, when the amount is not zero;
 * slot 102 of the vtable at 0x16d2818 (its pointer at 0x16d2b58); the other
 * slots of that vtable keep the same pairs of totals and counts. The record
 * types are not traced. Class and method unknown. */
struct Record013c8790 { /* derived name */
    u32 unknown0;
};

struct Object013c8790 { /* derived name */
    u8 unknown0[0xc0];
    u64 unknownc0;
    u8 unknownc8[0xb0];
    u64 unknown178;
};

void FUN_013c8790(Object013c8790 *self, const Record013c8790 *record) /* derived name */
{
    u64 size = static_cast<u64>(record->unknown0) * 16;
    if (size) {
        self->unknownc0 += size;
        ++self->unknown178;
    }
}
