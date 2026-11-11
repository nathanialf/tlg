/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a virtual slot (in the vtable group at 0x16a7550): 0 when any
 * of the states at +0x530, +0x534 and +0x2bc is 1; otherwise whether any of
 * the states at +0x4d8, +0x4e0, +0x4dc, +0x4e4, +0x4e8, +0x4d4 and +0x2b8 is
 * 1, tested in that order. Class and method unknown. */
struct Object002b54a0 { /* derived name */
    u8 unknown0[0x2b8];
    int unknown2b8;
    int unknown2bc;
    u8 unknown2c0[0x4d4 - 0x2c0];
    int unknown4d4;
    int unknown4d8;
    int unknown4dc;
    int unknown4e0;
    int unknown4e4;
    int unknown4e8;
    u8 unknown4ec[0x530 - 0x4ec];
    int unknown530;
    int unknown534;
};

int FUN_002b54a0(const Object002b54a0 *self) /* derived name */
{
    if (self->unknown530 == 1 || self->unknown534 == 1 || self->unknown2bc == 1)
        return 0;
    if (self->unknown4d8 == 1 || self->unknown4e0 == 1 || self->unknown4dc == 1 ||
        self->unknown4e4 == 1 || self->unknown4e8 == 1 || self->unknown4d4 == 1)
        return 1;
    return self->unknown2b8 == 1;
}
