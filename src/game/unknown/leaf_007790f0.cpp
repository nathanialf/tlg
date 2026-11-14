/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: adds the float at +0xba4 of the record the pointer at +0x68
 * holds to the float at +0x22c8 of the same record, the sum first cleared to
 * 0 when the two have opposite signs (each sign taken from the float's bits
 * as -1 or 1, the value read again after the clear); slot 17 of the vtable at
 * 0x16ad098 (its pointer at 0x16ad130), FUN_007790c0's class. Class and
 * method unknown. */
struct Record007790f0 { /* derived name */
    u8 unknown0[0xba4];
    float unknownba4; /* +0xba4 */
    u8 unknownba8[0x22c8 - 0xba8];
    float unknown22c8; /* +0x22c8 */
};

struct Object007790f0 { /* derived name */
    u8 unknown0[0x68];
    Record007790f0 *unknown68;
};

/* derived name: -1 for a float whose sign bit is set, else 1 */
static inline int signOf(float value)
{
    union {
        float f;
        int i;
    } bits;

    bits.f = value;
    return (bits.i >> 31) | 1;
}

void FUN_007790f0(Object007790f0 *self) /* derived name */
{
    Record007790f0 *record = self->unknown68;
    if (signOf(record->unknown22c8) != signOf(record->unknownba4))
        record->unknown22c8 = 0.0f;
    record->unknown22c8 += self->unknown68->unknownba4;
}
