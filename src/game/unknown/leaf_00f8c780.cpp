/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores 0 in the int at +0x2a8; not in a vtable: FUN_00f8b450
 * passes its address (lea at 0xf8bf57) to FUN_00f90d00 with the pointer at
 * +0x220 of the object it has just cleared +0x2a8 of, a callback. Class and
 * method unknown. */
struct Object00f8c780 { /* derived name */
    u8 unknown0[0x2a8];
    int unknown2a8;
};

void FUN_00f8c780(Object00f8c780 *self) /* derived name */
{
    self->unknown2a8 = 0;
}
