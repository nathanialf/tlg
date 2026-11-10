/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: adds the 32-bit count at +0x0 of its argument times 8 to the
 * 64-bit total at 0xc8 and counts one at 0x180, when the amount is not zero;
 * slot 103 of the vtable at 0x16d2818 (its pointer at 0x16d2b60); the other
 * slots of that vtable keep the same pairs of totals and counts. The record
 * types are not traced. Class and method unknown. */
struct Record013c87b0 { /* derived name */
    u32 unknown0;
};

struct Object013c87b0 { /* derived name */
    u8 unknown0[0xc8];
    u64 unknownc8;
    u8 unknownd0[0xb0];
    u64 unknown180;
};

void FUN_013c87b0(Object013c87b0 *self, const Record013c87b0 *record) /* derived name */
{
    u64 size = static_cast<u64>(record->unknown0) * 8;
    if (size) {
        self->unknownc8 += size;
        ++self->unknown180;
    }
}
