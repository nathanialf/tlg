/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a virtual method (its address at 0x16b9ce8 in
 * .data.rel.ro): sets the rectangle at +0x17c0 to half the unsigned width and
 * height at +0x1d8 and +0x1dc (each converted to a float and back, as the
 * rectangle's ints are set from floats elsewhere), at the origin. Class and
 * method unknown. */
struct Object00cffc50 { /* derived name */
    u8 unknown0[0x1d8];
    u32 width;  /* +0x1d8, derived name */
    u32 height; /* +0x1dc, derived name */
    u8 unknown1e0[0x17c0 - 0x1e0];
    int unknown17c0; /* +0x17c0 */
    int unknown17c4; /* +0x17c4 */
    int unknown17c8; /* +0x17c8 */
    int unknown17cc; /* +0x17cc */
};

// NONMATCHING: list-ilp order: the base loads and converts the width before the height,
// both to floats before either back (`cvtsi2ss xmm0, eax; cvtsi2ss xmm1, ecx; cvttss2si
// eax, xmm0; cvttss2si ecx, xmm1`); the build takes the height first, one value at a time.
void FUN_00cffc50(Object00cffc50 *self) /* derived name */
{
    float halfWidth = self->width / 2;
    float halfHeight = self->height / 2;
    self->unknown17c0 = halfWidth;
    self->unknown17c4 = halfHeight;
    self->unknown17c8 = 0;
    self->unknown17cc = 0;
}
