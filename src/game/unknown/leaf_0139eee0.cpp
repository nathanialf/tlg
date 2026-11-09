/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the address of the next 12-byte entry of the array at
 * +0x14 and counts it in the unsigned int at +0x10 (zero-extended: unsigned);
 * slot 8 of the vtable at 0x16caee0 (its pointer at 0x16caf30), the vtable
 * stored by FUN_005114e0 FUN_01354780 FUN_01354f30; slot 8 of the vtable at
 * 0x16d0298 (its pointer at 0x16d02e8), the vtable stored by FUN_00bf9780
 * FUN_013a05f0; slot 8 of the vtable at 0x16d1c38 (its pointer at 0x16d1c88),
 * the vtable stored by FUN_00cd5ca0 FUN_013af5c0. Class and method unknown. */
struct Entry0139eee0 { /* derived name */
    u8 unknown0[12];
};

struct Object0139eee0 { /* derived name */
    u8 unknown0[0x10];
    unsigned unknown10;
    Entry0139eee0 unknown14[1]; /* the length is not traced */
};

Entry0139eee0 *FUN_0139eee0(Object0139eee0 *self) /* derived name */
{
    return &self->unknown14[self->unknown10++];
}
