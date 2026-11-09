/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the pointer at +0x28 is set, as an int (the
 * bool widened, movzbl); slot 3 of the vtable at 0x16be818 (its pointer at
 * 0x16be840), the vtable stored by FUN_00eb1170 FUN_00eb13f0 FUN_00eb1470.
 * Class and method unknown. */
struct Object013cca10 { /* derived name */
    u8 unknown0[0x28];
    void *unknown28; /* type not traced */
};

int FUN_013cca10(const Object013cca10 *self) /* derived name */
{
    return self->unknown28 != 0;
}
