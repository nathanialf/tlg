/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the 32-bit word at +0x25c; slot 17 of the vtable at
 * 0x16aac80 (its pointer at 0x16aad18), the vtable stored by FUN_00506af0
 * FUN_00506ef0. Class and method unknown. */
struct Object013541d0 { /* derived name */
    u8 unknown0[0x258];
    u8 unknown258[4]; /* its address returned by FUN_01354190; type not traced */
    u32 unknown25c; /* bits returned by FUN_013541d0, stored by FUN_013541e0 and cleared by FUN_01354200 (both also set bit 4 of the byte at +0x20) */
    u8 unknown260[0x1c]; /* its address returned by FUN_01354180; type not traced */
    int unknown27c;      /* returned by FUN_01354210 */
};

u32 FUN_013541d0(const Object013541d0 *self) /* derived name */
{
    return self->unknown25c;
}
