/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 8 of the vtable at 0x16ae1c0: the byte offset of the
 * element (x, y, z), with the element size at +0x24, the width at +0x18 and
 * the height at +0x1c, stored to the output; returns 0. Class and method
 * unknown. */
struct Object001aac50 { /* derived name */
    u8 unknown0[0x18];
    u32 width;  /* derived name */
    u32 height; /* derived name */
    u8 unknown20[4];
    u32 elementSize; /* derived name */
};

// NONMATCHING: list-ilp order and greedy's assignment, the base zero-extends z into edi (self's
// register, dead after the height load) before the first add, the compile into ecx after it;
// the operand orders compile the same and 3.8.1 and 3.9.1 give this compile's form
int FUN_001aac50(const Object001aac50 *self, u64 *offset, u32 x, u32 y, u32 z) /* derived name */
{
    u32 rowPitch = self->width * self->elementSize;
    u32 slicePitch = rowPitch * self->height;
    *offset =
        x * self->elementSize + static_cast<u64>(y) * rowPitch + static_cast<u64>(z) * slicePitch;
    return 0;
}
