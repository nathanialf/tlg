/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 2 of a soldier AI mode, slot 2 of the vtable at
 * 0x16b3910 (stored by FUN_00abf490): asks FUN_00abf840 for the owner's (+0x8)
 * current mode; when the mode's own int at +0x18 is 4, returns that mode,
 * or the owner's pointer at +0x10 when the mode is this one; otherwise
 * returns the mode only when its int at +0x10 is 13. The types are not
 * traced beyond these fields. Class and method unknown. */
struct Owner00abf840; /* derived name */

struct Mode00acd550 { /* derived name */
    u8 unknown0[0x8];
    Owner00abf840 *unknown8; /* +0x8: the owner */
    int unknown10;           /* +0x10 */
    u8 unknown14[4];
    int unknown18; /* +0x18 */
};

struct Owner00abf840 { /* derived name */
    u8 unknown0[0x10];
    Mode00acd550 *unknown10; /* +0x10 */
};

Mode00acd550 *FUN_00abf840(Owner00abf840 *owner); /* derived name */

Mode00acd550 *FUN_00acd550(Mode00acd550 *self) /* derived name */
{
    Mode00acd550 *mode = FUN_00abf840(self->unknown8);
    if (self->unknown18 == 4) {
        if (mode == self)
            return self->unknown8->unknown10;
        return mode;
    }
    if (mode && mode->unknown10 == 13)
        return mode;
    return 0;
}
