/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores its argument in the 32-bit word at +0x550; slot 39 of
 * the vtable at 0x16a7a50 (its pointer at 0x16a7b98), the vtable stored by
 * FUN_00297190 FUN_00297320; slot 39 of the vtable at 0x16a8260 (its pointer
 * at 0x16a83a8), the vtable stored by FUN_002eec50; slot 39 of the vtable at
 * 0x16ac218 (its pointer at 0x16ac360), the vtable stored by FUN_00681b50
 * FUN_00684c00; slot 39 of the vtable at 0x16ac3a8 (its pointer at 0x16ac4f0),
 * the vtable stored by FUN_00684a90 FUN_00685840; and 13 more. Class and
 * method unknown. */
struct Object0134a660 { /* derived name */
    u8 unknown0[0x4f8];
    u32 unknown4f8; /* bits returned by FUN_0134a660, stored by FUN_0134a670 and cleared by FUN_0134a690 (both also set bit 4 of the byte at +0x20) */
    u8 unknown4fc[0x550 - 0x4fc];
    u32 unknown550; /* bits returned by FUN_0134a6a0, stored by FUN_0134a6b0, set by FUN_0134a6c0, cleared by FUN_0134a6d0 */
};

void FUN_0134a6b0(Object0134a660 *self, u32 bits) /* derived name */
{
    self->unknown550 = bits;
}
