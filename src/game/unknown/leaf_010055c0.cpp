/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the int its argument points to equals entry n
 * of the int array the pointer at +0x8 holds, n the int the pointer at +0x10
 * points to, as an int; slot 2 of the vtable at 0x16c0960 (its pointer at
 * 0x16c0980). Class and method unknown. */
struct Object010055c0 { /* derived name */
    u8 unknown0[8];
    int *unknown8;
    int *unknown10;
};

int FUN_010055c0(const Object010055c0 *self, const int *value) /* derived name */
{
    return self->unknown8[*self->unknown10] == *value;
}
