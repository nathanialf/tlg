/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: adds the 32-bit count at +0xc of its argument times 32 to the
 * 64-bit total at 0x48 and counts one at 0x100, when the amount is not zero;
 * slot 106 of the vtable at 0x16d2818 (its pointer at 0x16d2b78); the other
 * slots of that vtable keep the same pairs of totals and counts. The record
 * types are not traced. Class and method unknown. */
struct Record013c87f0 { /* derived name */
    u8 unknown0[0xc];
    u32 unknownc;
};

struct Object013c87f0 { /* derived name */
    u8 unknown0[0x48];
    u64 unknown48;
    u8 unknown50[0xb0];
    u64 unknown100;
};

void FUN_013c87f0(Object013c87f0 *self, const Record013c87f0 *record) /* derived name */
{
    u64 size = static_cast<u64>(record->unknownc) * 32;
    if (size) {
        self->unknown48 += size;
        ++self->unknown100;
    }
}
