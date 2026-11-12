/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_simd.h"

/* derived names: when the int at +0x120 is nonzero, copies the 16-byte vectors
 * at +0x13c0 and +0x13e0 of the record the pointer at +0x68 holds to its
 * +0xba0 and +0xb90 (the pointer reloaded between: the store may alias the
 * object); slot 14 of the vtable at 0x16acf08 (its pointer at 0x16acf88),
 * stored by FUN_00777e10. The record's other fields are not traced. */
struct Member00778170_68 { /* derived name */
    u8 unknown0[0xb90];
    Vec4 unknownb90;
    Vec4 unknownba0;
    u8 unknownbb0[0x810];
    Vec4 unknown13c0;
    u8 unknown13d0[0x10];
    Vec4 unknown13e0;
};

struct Object00778170 { /* derived name */
    u8 unknown0[0x68];
    Member00778170_68 *unknown68;
    u8 unknown70[0x90];
    Vec4 unknown100; /* a pending vector, (0, 0, 0, 1) when none */
    Vec4 unknown110; /* a pending rotation, (0, 0, 0, 1) when none */
    int unknown120;
};

void FUN_007196a0(Member00778170_68 *member); /* derived name */

/* derived name: two floats ordered and not equal (`vucomiss; jne`, no `jp`) */
static inline bool differs(float a, float b)
{
    return a < b || a > b;
}

void FUN_00778170(Object00778170 *self) /* derived name */
{
    if (self->unknown120) {
        self->unknown68->unknownba0 = self->unknown68->unknown13c0;
        self->unknown68->unknownb90 = self->unknown68->unknown13e0;
    }
}

/* derived names: slot 7 of the same vtable (its pointer at 0x16acf50): calls
 * FUN_007196a0 on the record, then hands it the pending vector at +0x100
 * (when x, y or z is not zero) at +0xba0 and the pending rotation at +0x110
 * (when it is not (0, 0, 0, 1)) at +0xb90, each set back to (0, 0, 0, 1) */
// NONMATCHING: the compares: the base tests each lane ordered and not equal with one `vucomiss 0,
// [lane]; jne` (no `jp`); written `a < b || a > b` the build keeps two compares (`seta; ja;
// test`) and as `!=` it adds `jp`: the source form of an ordered not-equal is not found
void FUN_00778080(Object00778170 *self) /* derived name */
{
    FUN_007196a0(self->unknown68);
    if (differs(lane(self->unknown100, 0), 0.0f) || differs(lane(self->unknown100, 1), 0.0f) ||
        differs(lane(self->unknown100, 2), 0.0f)) {
        self->unknown68->unknownba0 = self->unknown100;
        self->unknown100 = _mm_setr_ps(0.0f, 0.0f, 0.0f, 1.0f);
    }
    if (differs(lane(self->unknown110, 0), 0.0f) || differs(lane(self->unknown110, 1), 0.0f) ||
        differs(lane(self->unknown110, 2), 0.0f) || differs(lane(self->unknown110, 3), 1.0f)) {
        self->unknown68->unknownb90 = self->unknown110;
        self->unknown110 = _mm_setr_ps(0.0f, 0.0f, 0.0f, 1.0f);
    }
}
