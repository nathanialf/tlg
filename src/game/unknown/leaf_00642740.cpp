/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a condition returning whether the pointer at +0x230 of the
 * record at +0x40 of the object the pointer at 0x57c9390 holds is not null and
 * equals the pointer at +0x1f0 of the same record. FUN_00640dc0 registers it
 * under "IsBoy_TrackingTrico" (the kind 1; lea at 0x64116e), as
 * leaf_00644e90.cpp's condition; the registered conditions take no parameters
 * and return a bool in al. */

struct Member057c9390_40 { /* derived name */
    u8 unknown0[0x1f0];
    void *unknown1f0;
    u8 unknown1f8[0x38];
    void *unknown230;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x40];
    Member057c9390_40 *unknown40;
};

extern Object057c9390 *D_57c9390;

bool FUN_00642740() /* derived name */
{
    Member057c9390_40 *record = D_57c9390->unknown40;
    if (!record->unknown230)
        return false;
    return record->unknown230 == record->unknown1f0;
}
