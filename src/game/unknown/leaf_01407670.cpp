/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 0 of the vtables at 0x16d5930 and 0x16d7d10: clears the
 * ints at +0x10, +0x18, +0x28, +0x38, +0x3c and +0x30, in that order. Class
 * and method unknown. */
struct Object01407670 { /* derived name */
    u8 unknown0[0x10];
    int unknown10;
    u8 unknown14[4];
    int unknown18;
    u8 unknown1c[0xc];
    int unknown28;
    u8 unknown2c[4];
    int unknown30;
    u8 unknown34[4];
    int unknown38;
    int unknown3c;
};

void FUN_01407670(Object01407670 *self) /* derived name */
{
    self->unknown10 = 0;
    self->unknown18 = 0;
    self->unknown28 = 0;
    self->unknown38 = 0;
    self->unknown3c = 0;
    self->unknown30 = 0;
}
