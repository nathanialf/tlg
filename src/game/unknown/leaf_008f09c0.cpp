/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the pointer at +0x40 is set, as an int (the
 * bool widened, movzbl); slot 10 of the vtable at 0x16b06b0 (its pointer at
 * 0x16b0710), the vtable stored by FUN_008ef8a0 FUN_008efe80, the only
 * reference. Class and method unknown. */
struct Object008f09c0 { /* derived name */
    u8 unknown0[0x40];
    void *unknown40; /* type not traced */
};

int FUN_008f09c0(const Object008f09c0 *self) /* derived name */
{
    return self->unknown40 != 0;
}
