/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: decrements the int at +0x22c atomically (`lock dec`, the
 * result unused); slot 4 of the vtable at 0x16a7a50 (its pointer at
 * 0x16a7a80), the vtable stored by FUN_00297190 FUN_00297320; slot 4 of the
 * vtable at 0x16a7ce8 (its pointer at 0x16a7d18), the vtable stored by
 * FUN_002a8650 FUN_002a87b0 FUN_002a8810; slot 4 of the vtable at 0x16a7ea8
 * (its pointer at 0x16a7ed8), the vtable stored by FUN_002ae3c0 FUN_002aec50;
 * slot 4 of the vtable at 0x16a7f18 (its pointer at 0x16a7f48), the vtable
 * stored by FUN_002b4bf0 FUN_002b5080; and 111 more. Class and method unknown. */
struct
    Value0134a530 { /* derived name: 8 bytes copied as one, alignment 4 (the field's offset); type not traced */
    u8 unknown0[8];
};

struct Object0134a660 { /* derived name */
    u8 unknown0[0x20];
    u8 unknown20; /* bit 4 set by FUN_0134a670, FUN_0134a680 and FUN_0134a690 */
    u8 unknown21[0x22c - 0x21];
    int unknown22c; /* a count, decremented atomically by FUN_0134a3a0 */
    u8 unknown230[0x4f4 - 0x230];
    u8 unknown4f4[4]; /* its address returned by FUN_0134a3e0; type not traced */
    u32 unknown4f8; /* bits returned by FUN_0134a660, stored by FUN_0134a670, set by FUN_0134a680 and cleared by FUN_0134a690 (each also sets bit 4 of the byte at +0x20) */
    Value0134a530 unknown4fc; /* its address returned by FUN_0134a3d0, copied in by FUN_0134a530 */
    u8 unknown504[4];         /* its address returned by FUN_0134a3f0; type not traced */
    u8 unknown508[4];         /* its address returned by FUN_0134a400; type not traced */
    u8 unknown50c[0x14];      /* its address returned by FUN_0134a410; type not traced */
    u8 unknown520[0x10];      /* its address returned by FUN_0134a430; type not traced */
    u8 unknown530[0x10];      /* its address returned by FUN_0134a440; type not traced */
    u8 unknown540[0xc];       /* its address returned by FUN_0134a3b0; type not traced */
    u8 unknown54c[4];         /* its address returned by FUN_0134a3c0; type not traced */
    u32 unknown550; /* bits returned by FUN_0134a6a0, stored by FUN_0134a6b0, set by FUN_0134a6c0, cleared by FUN_0134a6d0 */
    u8 unknown554[0x558 - 0x554];
    u8 unknown558[4]; /* its address returned by FUN_0134a420; type and size not traced */
    u8 unknown55c[0x578 - 0x55c];
    float unknown578; /* returned by FUN_0134a6e0 */
};

void FUN_0134a3a0(Object0134a660 *self) /* derived name */
{
    __sync_fetch_and_sub(&self->unknown22c, 1);
}
