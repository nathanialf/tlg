/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 7 of the vtable at 0x16b3640 (stored by FUN_00abf490;
 * slot 5 is FUN_00ac2320): hands null to FUN_00489140 for the object the
 * pointer at +0x900 of the record at +0x38 of the object at 0x57c9390 holds
 * and clears its bool at +0x104; then, unless the byte at +0x1e is set, when
 * the object at +0x390 of the one the owner at +0x8 points to has its bool
 * at +0x39 set, clears the bool at +0x1e5 of the same member and sets the
 * byte at +0x1e. The game object is read again after the call and kept
 * (`mov rax, [0x57c9390]` once after it). The fields' meanings are not
 * traced. */
struct Object016b9108;

struct Member057c9390_38_900 { /* derived name */
    u8 unknown0[0x104];
    bool unknown104;
    u8 unknown105[0xe0];
    bool unknown1e5;
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

struct Object00ac27e0_390 { /* derived name */
    u8 unknown0[0x39];
    bool unknown39;
};

struct Object00ac27e0_8 { /* derived name */
    u8 unknown0[0x390];
    Object00ac27e0_390 *unknown390;
};

struct Object00ac27e0 { /* derived name */
    u8 unknown0[0x8];
    Object00ac27e0_8 **unknown8;
    u8 unknown10[0xe];
    bool unknown1e;
};

void FUN_00489140(Member057c9390_38_900 *member, Object016b9108 *object); /* derived name */

void FUN_00ac27e0(Object00ac27e0 *self) /* derived name */
{
    FUN_00489140(D_57c9390->unknown38->unknown900, 0);
    Object057c9390 *game = D_57c9390;
    game->unknown38->unknown900->unknown104 = false;
    if (!self->unknown1e) {
        Object00ac27e0_390 *held = (*self->unknown8)->unknown390;
        if (held && held->unknown39) {
            game->unknown38->unknown900->unknown1e5 = false;
            self->unknown1e = true;
        }
    }
}
