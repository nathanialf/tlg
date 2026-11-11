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
    u8 unknown70[0xb0];
    int unknown120;
};

void FUN_00778170(Object00778170 *self) /* derived name */
{
    if (self->unknown120) {
        self->unknown68->unknownba0 = self->unknown68->unknown13c0;
        self->unknown68->unknownb90 = self->unknown68->unknown13e0;
    }
}
