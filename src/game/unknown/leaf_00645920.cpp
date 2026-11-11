/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a condition returning, when the object the pointer at +0x1a0
 * of the record at +0x40 of the object the pointer at 0x57c9390 holds is not
 * null, bit 4 of its byte at +0x2424 (one-bit bitfields, cookbook 1160), and
 * else false. FUN_00640dc0 registers it under "IsCamera_Path" (the kind 1; lea
 * at 0x641b19), as leaf_00644e90.cpp's condition; the registered conditions
 * take no parameters and return a bool in al. */
struct Member057c9390_40_1a0 { /* derived name */
    u8 unknown0[0x2422];
    bool unknown2422_0 : 1;
    bool unknown2422_1 : 1;
    bool unknown2422_2 : 1;
    bool unknown2422_3 : 1;
    bool unknown2422_4 : 1;
    bool unknown2422_5 : 1;
    bool unknown2422_6 : 1;
    u8 unknown2423;
    bool unknown2424_0 : 1;
    bool unknown2424_1 : 1;
    bool unknown2424_2 : 1;
    bool unknown2424_3 : 1;
    bool unknown2424_4 : 1;
    bool unknown2424_5 : 1;
    bool unknown2424_6 : 1;
    u8 unknown2425[0x20];
    bool unknown2445_0 : 1;
    bool unknown2445_1 : 1;
    bool unknown2445_2 : 1;
    bool unknown2445_3 : 1;
    bool unknown2445_4 : 1;
    bool unknown2445_5 : 1;
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

bool FUN_00645920() /* derived name */
{
    Member057c9390_40_1a0 *object = D_57c9390->unknown40->unknown1a0;
    if (!object)
        return false;
    return object->unknown2424_4;
}
