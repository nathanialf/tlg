/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the int at +0xe0; slot 6 of the vtable at 0x16b79f0
 * (its pointer at 0x16b7a30), the vtable stored by FUN_00be4000 FUN_00be48c0
 * FUN_00be4960. The int is the `mov eax` width; its meaning is not traced.
 * Class and method unknown. */
struct Object00be4a70 { /* derived name */
    u8 unknown0[0xe0];
    int unknowne0;
};

int FUN_00be4a70(const Object00be4a70 *self) /* derived name */
{
    return self->unknowne0;
}
