/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the address of the field at +0x260; slot 12 of the
 * vtable at 0x16aac80 (its pointer at 0x16aacf0), the vtable stored by
 * FUN_00506af0 FUN_00506ef0. The field's type is not traced: its extent is the
 * distance to the next field, held as bytes. Class and method unknown. */
struct
    Value013541a0 { /* derived name: 8 bytes copied as one, alignment 4 (the field's offset); type not traced */
    u8 unknown0[8];
};

struct Object013541d0 { /* derived name */
    u8 unknown0[0x20];
    u8 unknown20; /* bit 4 set by FUN_013541e0, FUN_013541f0 and FUN_01354200 */
    u8 unknown21[0x258 - 0x21];
    u8 unknown258[4]; /* its address returned by FUN_01354190; type not traced */
    u32 unknown25c; /* bits returned by FUN_013541d0, stored by FUN_013541e0, set by FUN_013541f0 and cleared by FUN_01354200 (each also sets bit 4 of the byte at +0x20) */
    Value013541a0 unknown260; /* its address returned by FUN_01354180, copied in by FUN_013541a0 */
    float unknown268;         /* stored by FUN_013541c0 */
    u8 unknown26c[0x27c - 0x26c];
    int unknown27c; /* returned by FUN_01354210 */
};

Value013541a0 *FUN_01354180(Object013541d0 *self) /* derived name */
{
    return &self->unknown260;
}
