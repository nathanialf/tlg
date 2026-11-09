/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: counts one more in the int at +0x8 and adds its third
 * argument rounded up to a multiple of 16 to the int at +0xc, returning 0; the
 * second argument is unused and its type not traced; slot 0 of the vtable at
 * 0x16b7f80 (its pointer at 0x16b7f90), the vtable stored by FUN_005269a0
 * FUN_0058c760 FUN_00aec5d0 FUN_00c04990 FUN_00c0aeb0 FUN_00c0e890. Class and
 * method unknown. */
struct Object00c19aa0 { /* derived name */
    u8 unknown0[8];
    int unknown8;
    int unknownc;
};

int FUN_00c19aa0(Object00c19aa0 *self, void *, int size) /* derived name */
{
    ++self->unknown8;
    self->unknownc += (size + 15) & ~15;
    return 0;
}
