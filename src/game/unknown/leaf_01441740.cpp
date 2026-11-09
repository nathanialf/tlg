/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears the int at +0x8 and copies the 16-byte vector at +0x30
 * to +0x50 (vmovaps: aligned); slot 0 of the vtable at 0x16d60d0 (its pointer
 * at 0x16d60e0), the vtable stored by FUN_0114db30. Class and method unknown. */
#include "tlg_simd.h"

struct Object01441740 { /* derived name */
    u8 unknown0[8];
    int unknown8;
    u8 unknownc[0x30 - 0xc];
    Vec4 unknown30;
    u8 unknown40[0x10];
    Vec4 unknown50;
};

void FUN_01441740(Object01441740 *self) /* derived name */
{
    self->unknown8 = 0;
    self->unknown50 = self->unknown30;
}
