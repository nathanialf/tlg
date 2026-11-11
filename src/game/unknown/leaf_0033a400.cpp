/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 0 of the vtable at 0x16a86c0 (its pointer at
 * 0x16a86d0): copies six 32-bit values of the object into its argument, +0xc
 * to +0x3a0, +0x14 to +0x3b0, +0x10 to +0x3ac, +0x18 to +0x2a8, +0x1c to
 * +0x340 and +0x20 to +0x344. The classes and the values' types are not
 * traced. */
struct Object0033a400 { /* derived name */
    u8 unknown0[0xc];
    u32 unknownc;
    u32 unknown10;
    u32 unknown14;
    u32 unknown18;
    u32 unknown1c;
    u32 unknown20;
};

struct Argument0033a400 { /* derived name */
    u8 unknown0[0x2a8];
    u32 unknown2a8;
    u8 unknown2ac[0x94];
    u32 unknown340;
    u32 unknown344;
    u8 unknown348[0x58];
    u32 unknown3a0;
    u8 unknown3a4[0x8];
    u32 unknown3ac;
    u32 unknown3b0;
};

void FUN_0033a400(const Object0033a400 *self, Argument0033a400 *argument) /* derived name */
{
    argument->unknown3a0 = self->unknownc;
    argument->unknown3b0 = self->unknown14;
    argument->unknown3ac = self->unknown10;
    argument->unknown2a8 = self->unknown18;
    argument->unknown340 = self->unknown1c;
    argument->unknown344 = self->unknown20;
}
