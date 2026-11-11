/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the call slot (slot 2) of the callable holder whose vtable is at
 * 0x16af9b0 (stored by FUN_0088b4e0 FUN_008b0990 FUN_008b09e0): adds the float its argument points to to the float at
 * +0x48 of the record at +0x100 of the object the pointer at 0x57c9390 holds
 * counted in fiftieths (times 50), keeps the sum between 0 and 100 and
 * stores it back divided by 50 (times 0.02), returning the kept sum (xmm0
 * stays live past the store, so the stored product takes xmm1; the call
 * slot's return type is that of the holder's function). The object itself is
 * not read. */
struct Object008b0a30; /* derived name */

struct Member057c9390_100 { /* derived name */
    u8 unknown0[0x48];
    float unknown48;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x100];
    Member057c9390_100 *unknown100;
};

extern Object057c9390 *D_57c9390;

float FUN_008b0a30(Object008b0a30 *, const float *delta) /* derived name */
{
    Member057c9390_100 *record = D_57c9390->unknown100;
    float percent = record->unknown48 * 50.0f + *delta;
    percent = percent < 0.0f ? 0.0f : percent;
    percent = percent < 100.0f ? percent : 100.0f;
    record->unknown48 = percent * 0.02f;
    return percent;
}
