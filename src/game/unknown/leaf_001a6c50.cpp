/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: no reference to it was found in the executable. With no
 * output it returns 0x80d30000; otherwise it passes its two values with the
 * descriptor's byte count of the 16-bit field at +0x30 (rounded up from
 * bits), bit 0 of +0x28 and whether bits 8 to 12 of +0x2c are 0x12, to
 * FUN_001a6b50, stores four times the result and returns 0. The descriptor's
 * type is not traced. */
struct Descriptor001a6c50 { /* derived name */
    u8 unknown0[0x28];
    u32 unknown28;
    u32 unknown2c;
    u16 unknown30;
};

u32 FUN_001a6b50(u32 first, u32 bytes, u32 second, u32 flag, bool kind); /* derived name */

// NONMATCHING: list-ilp order, the descriptor's three fields loaded in the
// reverse of the base's (+0x30, +0x28, +0x2c), and the result copied before the shift.
int FUN_001a6c50(u32 *out, const Descriptor001a6c50 *descriptor, u32 first,
                 u32 second) /* derived name */
{
    if (!out)
        return 0x80d30000;
    *out = FUN_001a6b50(first, (descriptor->unknown30 + 7) >> 3, second, descriptor->unknown28 & 1,
                        (descriptor->unknown2c & 0x1f00) == 0x1200) *
           4;
    return 0;
}
