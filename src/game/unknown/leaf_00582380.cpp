/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback (its address taken by FUN_005821f0): calls
 * FUN_005823a0 with its arguments when the int at +0x40 of the record its
 * second argument points to is 1, and returns 0. The types are not traced. */
struct Record00582380 { /* derived name */
    u8 unknown0[0x40];
    int unknown40;
};

struct Object00582380; /* derived name */

void FUN_005823a0(Object00582380 *self, Record00582380 **record); /* derived name */

// NONMATCHING: shrink-wrapping: 4.0.0 places push rbp after the early test (ShrinkWrap.cpp, enabled by X86FrameLowering.cpp:2722-2725 under a frame pointer); the base sets up the frame at entry, as every one of the region's 12,521 framed functions does
int FUN_00582380(Object00582380 *self, Record00582380 **record) /* derived name */
{
    if ((*record)->unknown40 == 1) {
        FUN_005823a0(self, record);
    }
    return 0;
}
