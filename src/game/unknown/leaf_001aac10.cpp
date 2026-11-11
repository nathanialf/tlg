/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores the byte offset of the element at (x, y, z) of a
 * linear surface: the bits per element at +0x24 times x, plus y rows (the
 * width at +0x18 times the bits per element) and z slices (a row times the
 * height at +0x1c), the bit sum shifted down by 3, and returns 0; returns
 * 0x80d30000 without an output, as the format table's readers in
 * leaf_001a72a0.cpp do. The record's type is not traced. */
struct Surface001aac10 /* derived name */
{
    u8 unknown0[0x18];
    u32 unknown18; /* +0x18: the width */
    u32 unknown1c; /* +0x1c: the height */
    u8 unknown20[4];
    u32 unknown24; /* +0x24: the bits per element */
};

// NONMATCHING: list-ilp order and greedy's assignment: the build zero-extends z (mov ecx, r8d) after the first add and reuses rcx, the base before it into edi (self dead); the sum regrouped gives the same
int FUN_001aac10(const Surface001aac10 *self, u64 *out, u32 x, u32 y, u32 z) /* derived name */
{
    if (!out) {
        return 0x80d30000;
    }
    u32 bits = self->unknown24;
    u32 row = self->unknown18 * bits;
    u32 slice = row * self->unknown1c;
    *out = ((u64)(x * bits) + (u64)y * row + (u64)z * slice) >> 3;
    return 0;
}
