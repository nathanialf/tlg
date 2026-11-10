/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: adds the 32-bit count at +0xc of its argument plus one, times
 * 8 to the 64-bit total at 0x30 and counts one at 0xe8, when the amount is not
 * zero; slot 99 of the vtable at 0x16d2818 (its pointer at 0x16d2b40); the
 * other slots of that vtable keep the same pairs of totals and counts. The
 * record types are not traced. Class and method unknown. */
struct Record013c8750 { /* derived name */
    u8 unknown0[0xc];
    u32 unknownc;
};

struct Object013c8750 { /* derived name */
    u8 unknown0[0x30];
    u64 unknown30;
    u8 unknown38[0xb0];
    u64 unknowne8;
};

void FUN_013c8750(Object013c8750 *self, const Record013c8750 *record) /* derived name */
{
    u32 count = record->unknownc + 1;
    if (count) {
        self->unknown30 += static_cast<u64>(count) * 8;
        ++self->unknowne8;
    }
}
