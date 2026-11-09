/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_0095b640 on the object when the int at +0x1f0 is
 * non-zero, FUN_0095b160 otherwise, as tail calls. Their other parameters and
 * return types are not traced; slot 10 of the vtable at 0x16c7b78 (its pointer
 * at 0x16c7bd8), the vtable stored by FUN_00958460 FUN_0137e6e0. Class and
 * method unknown. */
struct Object0095b960 { /* derived name */
    u8 unknown0[0x1f0];
    int unknown1f0;
};

void FUN_0095b640(Object0095b960 *self); /* derived name */
void FUN_0095b160(Object0095b960 *self); /* derived name */

void FUN_0095b960(Object0095b960 *self) /* derived name */
{
    if (self->unknown1f0) {
        FUN_0095b640(self);
    } else {
        FUN_0095b160(self);
    }
}
