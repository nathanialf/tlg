/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the address of the field at +0x504; slot 19 of the
 * vtable at 0x16a7a50 (its pointer at 0x16a7af8), the vtable stored by
 * FUN_00297190 FUN_00297320; slot 19 of the vtable at 0x16a8260 (its pointer
 * at 0x16a8308), the vtable stored by FUN_002eec50; slot 19 of the vtable at
 * 0x16ac218 (its pointer at 0x16ac2c0), the vtable stored by FUN_00681b50
 * FUN_00684c00; slot 19 of the vtable at 0x16ac3a8 (its pointer at 0x16ac450),
 * the vtable stored by FUN_00684a90 FUN_00685840; and 13 more. The field's
 * type is not traced: its extent is the distance to the next field the slots
 * reach, held as bytes. Class and method unknown. */
struct Object0134a660 { /* derived name */
    u8 unknown0[0x22c];
    int unknown22c; /* a count, decremented atomically by FUN_0134a3a0 */
    u8 unknown230[0x4f4 - 0x230];
    u8 unknown4f4[4]; /* its address returned by FUN_0134a3e0; type not traced */
    u32 unknown4f8; /* bits returned by FUN_0134a660, stored by FUN_0134a670 and cleared by FUN_0134a690 (both also set bit 4 of the byte at +0x20) */
    u8 unknown4fc[8];    /* its address returned by FUN_0134a3d0; type not traced */
    u8 unknown504[4];    /* its address returned by FUN_0134a3f0; type not traced */
    u8 unknown508[4];    /* its address returned by FUN_0134a400; type not traced */
    u8 unknown50c[0x14]; /* its address returned by FUN_0134a410; type not traced */
    u8 unknown520[0x10]; /* its address returned by FUN_0134a430; type not traced */
    u8 unknown530[0x10]; /* its address returned by FUN_0134a440; type not traced */
    u8 unknown540[0xc];  /* its address returned by FUN_0134a3b0; type not traced */
    u8 unknown54c[4];    /* its address returned by FUN_0134a3c0; type not traced */
    u32 unknown550; /* bits returned by FUN_0134a6a0, stored by FUN_0134a6b0, set by FUN_0134a6c0, cleared by FUN_0134a6d0 */
    u8 unknown554[0x558 - 0x554];
    u8 unknown558[4]; /* its address returned by FUN_0134a420; type and size not traced */
};

u8 *FUN_0134a3f0(Object0134a660 *self) /* derived name */
{
    return self->unknown504;
}
