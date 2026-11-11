/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16afbb0 (+0x20 from the vtable stored at
 * 0x16afb90, slot 2): adds the float its argument points to to the float at
 * +0x58 of the record at +0x100 of the object the pointer at 0x57c9390 holds
 * counted in hundredths (as FUN_008b0b60 (leaf_008b0b60.cpp) returns it times
 * 100), keeps the sum between 0 and 100 and stores it back divided by 100
 * (times 0.01). The object itself is not read. */
struct Object008b14a0; /* derived name */

struct Member057c9390_100 { /* derived name */
    u8 unknown0[0x58];
    float unknown58;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x100];
    Member057c9390_100 *unknown100;
};

extern Object057c9390 *D_57c9390;

// NONMATCHING: greedy's assignment: the instructions are the base's but the product takes xmm0 where the base puts it in xmm1
void FUN_008b14a0(Object008b14a0 *, const float *delta) /* derived name */
{
    Member057c9390_100 *record = D_57c9390->unknown100;
    float percent = record->unknown58 * 100.0f + *delta;
    if (percent < 0.0f) {
        percent = 0.0f;
    }
    if (percent > 100.0f) {
        percent = 100.0f;
    }
    record->unknown58 = percent * 0.01f;
}
