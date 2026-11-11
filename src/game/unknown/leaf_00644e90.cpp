/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a condition returning whether the int at +0x2dc of the record
 * at +0x38 of the record at +0x108 of the object the pointer at 0x57c9390
 * holds is 1. FUN_00640dc0 registers it under "IsBoy_InCage" (the kind 1), its
 * id at 0x5810e80 and this address at 0x5810e88 (the id the result of
 * FUN_013baad0 for the string's FUN_013bad90 hash), as leaf_00645d70.cpp's
 * condition; the registered conditions take no parameters and return a bool in
 * al. */
struct Member057c9390_108_38 { /* derived name */
    u8 unknown0[0x2dc];
    int unknown2dc;
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

bool FUN_00644e90() /* derived name */
{
    return D_57c9390->unknown108->unknown38->unknown2dc == 1;
}
