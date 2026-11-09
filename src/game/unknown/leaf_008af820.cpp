/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the int at +0x140 of the record its pointer at +0x8
 * points to; slot 2 of the vtable at 0x16af5f0 (its pointer at 0x16af610), the
 * vtable stored by FUN_008af7a0 FUN_008af7e0. Class and method unknown. */
struct Target008af820 { /* derived name */
    u8 unknown0[0x140];
    int unknown140;
};

struct Object008af820 { /* derived name */
    u8 unknown0[0x8];
    Target008af820 *unknown8;
};

int FUN_008af820(const Object008af820 *self) /* derived name */
{
    return self->unknown8->unknown140;
}
