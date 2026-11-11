/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 11 of the vtable at 0x16cb520 (stored by FUN_006743e0; slots 0 and 1
 * are 0x511160 and 0x511170): calls FUN_00822e90 on the object, then, when the
 * int at +0x298 is nonzero or bit 4 of the flags byte at +0x20 is set, calls
 * FUN_0134d0e0 on it and clears both. 0x134d0a0 and 0x1360370 have this same
 * body. The types are not traced. Class and method unknown. */
struct Object01360370 { /* derived name */
    u8 unknown0[0x20];
    u8 unknown20; /* +0x20: flags, bit 4 */
    u8 unknown21[0x277];
    int unknown298; /* +0x298 */
};

void FUN_00822e90(Object01360370 *self); /* derived name */
void FUN_0134d0e0(Object01360370 *self); /* derived name */

void FUN_01360370(Object01360370 *self) /* derived name */
{
    FUN_00822e90(self);
    if (self->unknown298 != 0 || (self->unknown20 & 0x10)) {
        FUN_0134d0e0(self);
        self->unknown298 = 0;
        self->unknown20 &= ~0x10;
    }
}
