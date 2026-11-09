/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores its float argument (xmm0) at +0x4e04; slot 18 of the
 * vtable at 0x16ab238 (its pointer at 0x16ab2d8), the vtable stored by
 * FUN_00525530 FUN_00526520. Class and method unknown. */
struct Object0052d040 { /* derived name */
    u8 unknown0[0x4e04];
    float unknown4e04;
};

void FUN_0052d040(Object0052d040 *self, float value) /* derived name */
{
    self->unknown4e04 = value;
}
