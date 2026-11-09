/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores its float argument at +0x4e10; slot 19 of the vtable
 * at 0x16ab238 (its pointer at 0x16ab2e0), the vtable stored by FUN_00525530
 * FUN_00526520. Class and method unknown. */
struct Object01357f30 { /* derived name */
    u8 unknown0[0x4e10];
    float unknown4e10;
};

void FUN_01357f30(Object01357f30 *self, float value) /* derived name */
{
    self->unknown4e10 = value;
}
