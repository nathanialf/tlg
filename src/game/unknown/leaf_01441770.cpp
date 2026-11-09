/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears the int at +0x8 and copies the int at +0x18 to +0x20;
 * slot 0 of the vtable at 0x16d5f98 (its pointer at 0x16d5fa8), the vtable
 * stored by FUN_0114db30. Class and method unknown. */
struct Object01441770 { /* derived name */
    u8 unknown0[8];
    int unknown8;
    u8 unknownc[0x18 - 0xc];
    int unknown18;
    u8 unknown1c[0x20 - 0x1c];
    int unknown20;
};

void FUN_01441770(Object01441770 *self) /* derived name */
{
    self->unknown8 = 0;
    self->unknown20 = self->unknown18;
}
