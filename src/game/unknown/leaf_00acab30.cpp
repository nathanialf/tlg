/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears the flag at +0x48e of the record the pointer at +0x8
 * points to (through one more pointer) unless its argument is null or the int
 * at +0x10 of the argument is 6; slot 7 of the vtable at 0x16b37d0 (its
 * pointer at 0x16b3818). Class and method unknown. */
struct Record00acab30 { /* derived name */
    u8 unknown0[0x48e];
    bool unknown48e;
};

struct Object00acab30 { /* derived name */
    u8 unknown0[8];
    Record00acab30 **unknown8;
};

struct Event00acab30 { /* derived name */
    u8 unknown0[0x10];
    int unknown10;
};

void FUN_00acab30(Object00acab30 *self, const Event00acab30 *event) /* derived name */
{
    if (event && event->unknown10 != 6) {
        (*self->unknown8)->unknown48e = false;
    }
}
