/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the int at +0x188; slot 16 of the vtable at 0x16b64f8
 * (its pointer at 0x16b6588), the vtable stored by FUN_00b4aed0 FUN_00b4b060.
 * The int is the `mov eax` width; its meaning is not traced. Class and method
 * unknown. */
struct Object0139c340 { /* derived name */
    u8 unknown0[0x188];
    int unknown188;
};

int FUN_0139c340(const Object0139c340 *self) /* derived name */
{
    return self->unknown188;
}
