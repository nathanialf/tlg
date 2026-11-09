/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the int at +0x1ec; slot 30 of the vtable at 0x16be9a8
 * (its pointer at 0x16beaa8), the vtable stored by FUN_00eb3c90 FUN_00eb3fb0.
 * The int is the `mov eax` width; its meaning is not traced. Class and method
 * unknown. */
struct Object00ebf0e0 { /* derived name */
    u8 unknown0[0x1ec];
    int unknown1ec;
};

int FUN_00ebf0e0(const Object00ebf0e0 *self) /* derived name */
{
    return self->unknown1ec;
}
