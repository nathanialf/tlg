/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"

/* derived names: slot 5 of the vtable at 0x16b3550 (its pointer at
 * 0x16b3580), stored by FUN_00abf490 with the vtables of its siblings
 * (0x16b3640's slot 5 is FUN_00ac2320): when the object the owner at +0x8
 * points to has its object at +0xd68, sets that object's int at +0x294 to 3
 * when the owner's object at +0x390 exists with its bool at +0x2d set and
 * to 2 otherwise; then sets the owner's float at +0x4a4 to the float at
 * +0x44 of the object the pointer at +0x900 of the record at +0x38 of the
 * object at 0x57c9390 holds, plus 25 less up to 14.99 at random, and its own
 * float at +0x18 to that float plus 5. The fields' meanings are not
 * traced. */
struct Member057c9390_38_900 { /* derived name */
    u8 unknown0[0x44];
    float unknown44;
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

struct Object00ac0160_390 { /* derived name */
    u8 unknown0[0x2d];
    u8 unknown2d; /* +0x2d: compared with 0 (`cmp byte [rdx+0x2d], 0`) */
};

struct Object00ac0160_d68 { /* derived name */
    u8 unknown0[0x294];
    int unknown294;
};

struct Object00ac0160_8 { /* derived name */

    /* the int at +0x294 of the object at +0xd68, when there is one: 3 when
     * the object at +0x390 exists with its byte at +0x2d set, else 2 (as
     * FUN_00accd20 sets it) */
    void updateUnknown294() /* derived name */
    {
        if (unknownd68)
            unknownd68->unknown294 = unknown390 && unknown390->unknown2d != 0 ? 3 : 2;
    }

    u8 unknown0[0x390];
    Object00ac0160_390 *unknown390;
    u8 unknown398[0x10c];
    float unknown4a4;
    u8 unknown4a8[0x8c0];
    Object00ac0160_d68 *unknownd68;
};

struct Object00ac0160 { /* derived name */
    u8 unknown0[0x8];
    Object00ac0160_8 **unknown8;
    u8 unknown10[8];
    float unknown18;
};

void FUN_00ac0160(Object00ac0160 *self) /* derived name */
{
    (*self->unknown8)->updateUnknown294();
    Object00ac0160_8 *owner = *self->unknown8;
    owner->unknown4a4 =
        D_57c9390->unknown38->unknown900->unknown44 + (25.0f - 14.99f * (rand() / (float)RAND_MAX));
    self->unknown18 = D_57c9390->unknown38->unknown900->unknown44 + 5.0f;
}
