/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a condition FUN_00b10ec0 registers in its table (lea at
 * 0xb1235c), taking no parameters and returning a bool in al: whether the int
 * at +0x5cc of the object the pointer at 0x58325c0 holds and the int at +0x2d4
 * of the record at +0x38 of the record at +0x108 of the object the pointer at
 * 0x57c9390 holds are both nonzero. The objects' other fields are not traced. */
struct Object058325c0 { /* derived name */
    u8 unknown0[0x5cc];
    int unknown5cc;
};

extern Object058325c0 *D_58325c0;

struct Member057c9390_108_38 { /* derived name */
    u8 unknown0[0x2d4];
    int unknown2d4;
};

struct Member057c9390_108 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_108_38 *unknown38;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x108];
    Member057c9390_108 *unknown108;
};

extern Object057c9390 *D_57c9390;

bool FUN_00b10d50() /* derived name */
{
    if (D_58325c0->unknown5cc != 0 && D_57c9390->unknown108->unknown38->unknown2d4 != 0)
        return true;
    return false;
}
