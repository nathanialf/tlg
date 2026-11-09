/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores 1 in the int at +0x268; slot 11 of the vtable at
 * 0x16b1d98 (its pointer at 0x16b1e00), the vtable stored by FUN_00a2f660
 * FUN_00a2f810. The int is the store's width; its meaning is not traced. Class
 * and method unknown. */
struct Object0138c3a0 { /* derived name */
    u8 unknown0[0x268];
    int unknown268;
};

void FUN_0138c3a0(Object0138c3a0 *self) /* derived name */
{
    self->unknown268 = 1;
}
