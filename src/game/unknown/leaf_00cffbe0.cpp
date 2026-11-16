/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 13 of the vtable at 0x16b9cb0 (its pointer at
 * 0x16b9d18), the vtable stored by FUN_001afd70: records a code (0 to 255)
 * with a flag. With the flag set the code's count at +0x13b0 goes up and the
 * code, mapped through the table at 0x151e7c0 while the mode at +0x17bc is
 * set, is written to the ring of 256 codes at +0xfb0 at the position +0x17b4
 * counts; with it clear the code's count is cleared. Code 0x86 sets the mode
 * to the flag. Class and method unknown. */
struct Object00cffbe0 { /* derived name */
    u8 unknown0[0xfb0];
    int history[256]; /* +0xfb0, derived name */
    int counts[256];  /* +0x13b0, derived name */
    u8 unknown17b0[0x4];
    int position; /* +0x17b4, derived name */
    u8 unknown17b8[0x4];
    int mapped; /* +0x17bc, derived name */
};

extern const int D_151e7c0[256]; /* derived name: the code each code maps to */

void FUN_00cffbe0(Object00cffbe0 *self, int code, int flag) /* derived name */
{
    if (code == 0x86)
        self->mapped = flag != 0;
    if (flag) {
        self->counts[code]++;
        if (self->mapped)
            code = D_151e7c0[code];
        self->history[self->position++ % 256] = code;
    } else {
        self->counts[code] = 0;
    }
}
