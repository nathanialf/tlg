/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 2 of a soldier AI mode, slot 2 of the vtable at
 * 0x16b3730 (its pointer at 0x16b3750), the vtable stored by FUN_00abf490
 * (slot 3 returns the mode's id, "AIMODE_SOL_Init": leaf_00ac7410.cpp): when
 * the int at +0x480 of the owner's (+0x8) record at +0x0 is set, returns the
 * owner's pointer at +0x70; otherwise, when the record's int at +0x90 is 0,
 * the byte at +0x1e6 of the object at +0x900 of the record at +0x38 of the
 * object the pointer at 0x57c9390 holds is 0 and the mode's int at +0x24 is
 * 4, what FUN_00abf840 returns for the owner; else null. The types are not
 * traced beyond these fields. Class and method unknown. */
struct Record00ac6220 { /* derived name */
    u8 unknown0[0x90];
    int unknown90;
    u8 unknown94[0x480 - 0x94];
    int unknown480;
};

struct Owner00ac6220 { /* derived name */
    Record00ac6220 *unknown0;
    u8 unknown8[0x70 - 0x8];
    void *unknown70;
};

struct Member057c9390_38_900 { /* derived name */
    u8 unknown0[0x1e6];
    bool unknown1e6;
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

struct Mode00ac6220 { /* derived name */
    u8 unknown0[0x8];
    Owner00ac6220 *unknown8;
    u8 unknown10[0x24 - 0x10];
    int unknown24;
};

void *FUN_00abf840(Owner00ac6220 *owner); /* derived name */

// NONMATCHING: the base reloads the owner's record pointer before the +0x90 test and calls
// FUN_00abf840 and returns (a frame) where this tail-calls with one load: no call is marked
// tail in stage 1 (cookbook 2126's class), the stage-1 form not found
void *FUN_00ac6220(Mode00ac6220 *self) /* derived name */
{
    Owner00ac6220 *owner = self->unknown8;
    if (owner->unknown0->unknown480 != 0) {
        return owner->unknown70;
    }
    if (owner->unknown0->unknown90 != 0 || D_57c9390->unknown38->unknown900->unknown1e6 ||
        self->unknown24 != 4) {
        return 0;
    }
    return FUN_00abf840(owner);
}
