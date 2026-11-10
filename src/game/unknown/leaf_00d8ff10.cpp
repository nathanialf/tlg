/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback (its address taken by FUN_00d8f280): calls
 * FUN_00c57220 with the object when bit 3 of the byte at +0x25 is set (a
 * one-bit field, cookbook 1111), and returns 1. The types are not traced. */
struct Object00d8ff10 { /* derived name */
    u8 unknown0[0x25];
    u8 unknown25_0 : 1;
    u8 unknown25_1 : 1;
    u8 unknown25_2 : 1;
    u8 unknown25_3 : 1;
};

void FUN_00c57220(Object00d8ff10 *self); /* derived name */

// NONMATCHING: shrink-wrapping: 4.0.0 places push rbp after the early test (ShrinkWrap.cpp, enabled by X86FrameLowering.cpp:2722-2725 under a frame pointer); the base sets up the frame at entry, as every one of the region's 12,521 framed functions does
int FUN_00d8ff10(Object00d8ff10 *self) /* derived name */
{
    if (self->unknown25_3) {
        FUN_00c57220(self);
    }
    return 1;
}
