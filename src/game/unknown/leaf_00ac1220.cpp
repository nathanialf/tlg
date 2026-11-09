/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears the byte at +0x48e of the object the pointer at +0x0
 * of the record at +0x8 holds; slot 7 of the vtable at 0x16b35a0 (its pointer
 * at 0x16b35e8), the vtable stored by FUN_00abf490. Class and method unknown. */
struct Target00ac1220 { /* derived name */
    u8 unknown0[0x48e];
    bool unknown48e;
};

struct Record00ac1220 { /* derived name */
    Target00ac1220 *unknown0;
};

struct Object00ac1220 { /* derived name */
    u8 unknown0[8];
    Record00ac1220 *unknown8;
};

void FUN_00ac1220(Object00ac1220 *self) /* derived name */
{
    self->unknown8->unknown0->unknown48e = false;
}
