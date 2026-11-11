/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: adds the length in bytes of the range its argument holds (a begin
 * pointer at +0x0, an end at +0x8), when the begin is not null, to the 64-bit total at 0x20 and counts one at 0xd8, when the
 * amount is not zero; slot 104 of the vtable at 0x16d2818 (its pointer at 0x16d2b68);
 * the other slots of that vtable keep the same pairs of totals and counts. The
 * record types are not traced. Class and method unknown. */
struct Record013c87d0 { /* derived name */
    u8 *unknown0;
    u8 *unknown8;
};

struct Object013c87d0 { /* derived name */
    u8 unknown0[0x20];
    u64 unknown20;
    u8 unknown28[0xb0];
    u64 unknownd8;
};

void FUN_013c87d0(Object013c87d0 *self, const Record013c87d0 *record) /* derived name */
{
    if (record->unknown0) {
        u64 size = record->unknown8 - record->unknown0;
        if (size) {
            self->unknown20 += size;
            ++self->unknownd8;
        }
    }
}
