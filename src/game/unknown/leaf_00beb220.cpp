/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: increments the int at +0x8 and adds 4 to the int at +0xc, a
 * count and a byte total of 4-byte items, as it reads; slot 1 of the vtable at
 * 0x16b7be8 (its pointer at 0x16b7c00), the vtable stored by FUN_005269a0
 * FUN_0058c760 FUN_00aec5d0 FUN_00c04990 FUN_00c0aeb0. Class and method
 * unknown. */
struct Object00beb220 { /* derived name */
    u8 unknown0[0x8];
    int unknown8;
    int unknownc;
};

void FUN_00beb220(Object00beb220 *self) /* derived name */
{
    self->unknown8++;
    self->unknownc += 4;
}
