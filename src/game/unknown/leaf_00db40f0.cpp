/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the int at +0x5c of the record its pointer at +0x10
 * points to; slot 6 of the vtable at 0x16bc0a0 (its pointer at 0x16bc0e0), the
 * vtable stored by FUN_00ddbb60; slots 4 and 6 (FUN_00db4080, FUN_00db40f0)
 * read +0x58 and +0x5c. Class and method unknown. */
struct Target00db4080 { /* derived name */
    u8 unknown0[0x58];
    int unknown58;
    int unknown5c;
};

struct Object00db4080 { /* derived name */
    u8 unknown0[0x10];
    Target00db4080 *unknown10;
};

int FUN_00db40f0(const Object00db4080 *self) /* derived name */
{
    return self->unknown10->unknown5c;
}
