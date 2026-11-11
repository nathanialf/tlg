/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: copies the five ints at +0xc to +0x1c of the object to
 * +0x3a0, +0x3ac, +0x2a8, +0x340 and +0x344 of its second argument; slot 0 of
 * the vtable at 0x16a8ea0 (its pointer at 0x16a8eb0), stored by FUN_0039de50
 * (0x39f6a5 calls it). The fields' meanings are not traced. */
struct Object003a72a0 { /* derived name */
    u8 unknown0[0xc];
    int unknownc;
    int unknown10;
    int unknown14;
    int unknown18;
    int unknown1c;
};

struct Target003a72a0 { /* derived name */
    u8 unknown0[0x2a8];
    int unknown2a8;
    u8 unknown2ac[0x94];
    int unknown340;
    int unknown344;
    u8 unknown348[0x58];
    int unknown3a0;
    u8 unknown3a4[8];
    int unknown3ac;
};

void FUN_003a72a0(const Object003a72a0 *self, Target003a72a0 *target) /* derived name */
{
    target->unknown3a0 = self->unknownc;
    target->unknown3ac = self->unknown10;
    target->unknown2a8 = self->unknown14;
    target->unknown340 = self->unknown18;
    target->unknown344 = self->unknown1c;
}
