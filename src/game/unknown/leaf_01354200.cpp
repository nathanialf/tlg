/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears the bits of its argument in the 32-bit word at +0x25c
 * and sets bit 4 of the byte at +0x20; slot 20 of the vtable at 0x16aac80 (its
 * pointer at 0x16aad30), the vtable stored by FUN_00506af0 FUN_00506ef0. Class
 * and method unknown. */
struct
    Value013541a0 { /* derived name: 8 bytes copied as one, alignment 4 (the field's offset); type not traced */
    u8 unknown0[8];
};

struct Object013541d0 { /* derived name */
    u8 unknown0[0x20];
    u8 unknown20; /* bit 4 set by FUN_013541e0, FUN_013541f0 and FUN_01354200 */
    u8 unknown21[0x258 - 0x21];
    u32 unknown258; /* its address returned by FUN_01354190, stored by FUN_013541b0; 32 bits wide, type not traced */
    u32 unknown25c; /* bits returned by FUN_013541d0, stored by FUN_013541e0, set by FUN_013541f0 and cleared by FUN_01354200 (each also sets bit 4 of the byte at +0x20) */
    Value013541a0 unknown260; /* its address returned by FUN_01354180, copied in by FUN_013541a0 */
    float unknown268;         /* stored by FUN_013541c0 */
    u8 unknown26c[0x27c - 0x26c];
    int unknown27c; /* returned by FUN_01354210 */
};

void FUN_01354200(Object013541d0 *self, u32 bits) /* derived name */
{
    self->unknown25c &= ~bits;
    self->unknown20 |= 0x10;
}
