/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 99 of the vtable at 0x16d2818 (its pointer at
 * 0x16d2b30): when the 64-bit word at +0x18 of its argument is set, the 32-bit
 * word at +0x10 plus 80 less the low half of that word, rounded down to 16, is
 * added to the 64-bit total at 0x28 and counted at 0xe0 when it is not zero,
 * as the vtable's other slots keep their pairs of totals and counts
 * (FUN_013c8540). The record types are not traced. Class and method unknown. */
struct Record013c8720 { /* derived name */
    u8 unknown0[0x10];
    u32 unknown10;
    u8 unknown14[4];
    u64 unknown18;
};

struct Object013c8720 { /* derived name */
    u8 unknown0[0x28];
    u64 unknown28;
    u8 unknown30[0xb0];
    u64 unknowne0;
};

// NONMATCHING: list-ilp order, the mask's `mov eax, 0xfffffff0` before the `add ecx, [rsi + 0x10]`
// (the base has the add first); 3.6.2, 3.7.1 and 3.8.1 give the base's order, 3.9.1 and 4.0.0 this one
// (round 135B, prebuilt releases)
void FUN_013c8720(Object013c8720 *self, const Record013c8720 *record) /* derived name */
{
    if (record->unknown18) {
        u64 size = (80 - record->unknown18 + record->unknown10) & 0xfffffff0;
        if (size) {
            self->unknown28 += size;
            ++self->unknowne0;
        }
    }
}
