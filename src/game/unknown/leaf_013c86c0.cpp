/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: adds the 32-bit count at +0xc of its argument times 16 to the
 * 64-bit total at 0x50 and counts one at 0x108, when the amount is not zero;
 * slot 91 of the vtable at 0x16d2818 (its pointer at 0x16d2b00); the other
 * slots of that vtable keep the same pairs of totals and counts. The record
 * types are not traced. Class and method unknown. */
struct Record013c86c0 { /* derived name */
    u8 unknown0[0xc];
    u32 unknownc;
};

struct Object013c86c0 { /* derived name */
    u8 unknown0[0x50];
    u64 unknown50;
    u8 unknown58[0xb0];
    u64 unknown108;
};

void FUN_013c86c0(Object013c86c0 *self, const Record013c86c0 *record) /* derived name */
{
    u64 size = static_cast<u64>(record->unknownc) * 16;
    if (size) {
        self->unknown50 += size;
        ++self->unknown108;
    }
}
