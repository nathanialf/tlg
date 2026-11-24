/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: slot 7 of the vtable at 0x16b4dc0 (stored by its
 * constructor; slots 0 and 1 are FUN_00b1b570 and FUN_00b1b580): the first
 * time (the int at +0x34 still 0, then set to 1) hands the object to
 * FUN_0081a930 with the object at +0x48 of the one the pointer at 0x57c9390
 * holds; then makes its name at +0x54 the name "EatenBarrelName", interned
 * as a copy, and hands its member at +0x58 to FUN_00b1b5a0 with
 * the object at +0x38 of its owner at +0x28, a tail call. The fields'
 * meanings are not traced. */
struct Member057c9390_48; /* derived name */

struct Object057c9390 { /* derived name */
    u8 unknown0[0x48];
    Member057c9390_48 *unknown48; /* +0x48 */
};

extern Object057c9390 *D_57c9390;

struct Target00b1b5a0; /* derived name */

struct Owner00b1b910 { /* derived name */
    u8 unknown0[0x38];
    Target00b1b5a0 *unknown38; /* +0x38 */
};

struct Object00b1b910 { /* derived name */
    u8 unknown0[0x28];
    Owner00b1b910 *owner; /* +0x28 */
    u8 unknown30[4];
    int unknown34; /* +0x34 */
    u8 unknown38[0x1c];
    Name name;       /* +0x54 */
    u8 unknown58[8]; /* +0x58: the member passed on; not traced */
};

void FUN_0081a930(Member057c9390_48 *member, Object00b1b910 *object); /* derived name */
void FUN_00b1b5a0(Target00b1b5a0 *target, void *member);              /* derived name */

void FUN_00b1b910(Object00b1b910 *self) /* derived name */
{
    if (self->unknown34 == 0) {
        self->unknown34 = 1;
        FUN_0081a930(D_57c9390->unknown48, self);
    }
    self->name = Name("EatenBarrelName", false);
    FUN_00b1b5a0(self->owner->unknown38, self->unknown58);
}
