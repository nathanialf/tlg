/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a condition returning whether bit 0 of the byte at +0x2423 of
 * the record at +0x1a0 of the record at +0x40 of the object the pointer at
 * 0x57c9390 holds is set. FUN_00640dc0 registers it under "IsBoy_FallLong"
 * (the kind 1), its id at 0x5810e60 and this address at 0x5810e68 (the id the
 * result of FUN_013baad0 for the string's FUN_013bad90 hash), as
 * leaf_00645d70.cpp's condition; the registered conditions take no parameters
 * and return a bool in al. */
struct Member057c9390_40_1a0 { /* derived name */
    u8 unknown0[0x2423];
    bool unknown2423_0
        : 1; /* bit 0 of the byte at +0x2423; the code at 0x63788b sets it (`or byte, 1`), 0x64a494 sets bit 1 */
};

struct Member057c9390_40 { /* derived name */
    u8 unknown0[0x1a0];
    Member057c9390_40_1a0 *unknown1a0;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x40];
    Member057c9390_40 *unknown40;
};

extern Object057c9390 *D_57c9390;

bool FUN_00644d10() /* derived name */
{
    return D_57c9390->unknown40->unknown1a0->unknown2423_0;
}
