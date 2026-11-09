/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the pointer at +0x108 is set, as an int (the
 * bool widened, movzbl); slot 22 of the vtable at 0x16ace40 (its pointer at
 * 0x16acf00), the vtable stored by FUN_00775ec0 FUN_00776130. Class and method
 * unknown. */
struct Object00777d20 { /* derived name */
    u8 unknown0[0x108];
    void *unknown108; /* type not traced */
};

int FUN_00777d20(const Object00777d20 *self) /* derived name */
{
    return self->unknown108 != 0;
}
