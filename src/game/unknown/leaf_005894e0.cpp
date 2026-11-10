/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback (its address taken by FUN_005f2b90): sets bit 5
 * (0x20) of the flags at +0x30 of its argument when the int at +0x1d8 is set,
 * clears it otherwise, and returns 0. The types are not traced. */
struct Target005894e0 { /* derived name */
    u8 unknown0[0x30];
    u32 unknown30; /* flags */
};

struct Object005894e0 { /* derived name */
    u8 unknown0[0x1d8];
    int unknown1d8;
};

int FUN_005894e0(Object005894e0 *self, Target005894e0 *target) /* derived name */
{
    if (self->unknown1d8) {
        target->unknown30 |= 0x20;
    } else {
        target->unknown30 &= ~0x20u;
    }
    return 0;
}
