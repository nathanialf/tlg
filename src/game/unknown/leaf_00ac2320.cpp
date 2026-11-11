/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears the bool at +0x104 of the object the pointer at +0x900
 * of the record at +0x38 of the object the pointer at 0x57c9390 holds, then
 * the object's bytes at +0x1c and +0x1d, sets its float at +0x18 to -1 and
 * clears its byte at +0x1e; slot 5 of the vtable at 0x16b3640 (its pointer at
 * 0x16b3678), stored by FUN_00abf490, its slot 0 the empty method
 * FUN_001af750. The fields' meanings are not traced. */
struct Member057c9390_38_900 { /* derived name */
    u8 unknown0[0x104];
    bool unknown104;
};

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x900];
    Member057c9390_38_900 *unknown900;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38;
};

extern Object057c9390 *D_57c9390;

struct Object00ac2320 { /* derived name */
    u8 unknown0[0x18];
    float unknown18;
    bool unknown1c;
    bool unknown1d;
    bool unknown1e;
};

void FUN_00ac2320(Object00ac2320 *self) /* derived name */
{
    D_57c9390->unknown38->unknown900->unknown104 = false;
    self->unknown1c = false;
    self->unknown1d = false;
    self->unknown18 = -1.0f;
    self->unknown1e = false;
}
