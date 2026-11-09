/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the int at +0x27c; slot 21 of the vtable at 0x16aac80
 * (its pointer at 0x16aad38), the vtable stored by FUN_00506af0 FUN_00506ef0.
 * Class and method unknown. */
struct Object013541d0 { /* derived name */
    u8 unknown0[0x25c];
    u32 unknown25c; /* bits returned by FUN_013541d0, stored by FUN_013541e0 and cleared by FUN_01354200 (both also set bit 4 of the byte at +0x20) */
    u8 unknown260[0x27c - 0x260];
    int unknown27c; /* returned by FUN_01354210 */
};

int FUN_01354210(const Object013541d0 *self) /* derived name */
{
    return self->unknown27c;
}
