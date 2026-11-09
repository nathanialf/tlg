/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the int at +0x164; slot 5 of the vtable at 0x16b91f0
 * (its pointer at 0x16b9228), the vtable stored by FUN_00cc9fa0 FUN_00cca6c0.
 * The int is the `mov eax` width; its meaning is not traced. Class and method
 * unknown. */
struct Object00cca7b0 { /* derived name */
    u8 unknown0[0x164];
    int unknown164;
};

int FUN_00cca7b0(const Object00cca7b0 *self) /* derived name */
{
    return self->unknown164;
}
