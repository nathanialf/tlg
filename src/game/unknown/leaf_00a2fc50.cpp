/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a virtual method (its address at 0x16b1df0 in
 * .data.rel.ro): when the int at +0x254 is set and the one at +0x258 is 1,
 * and the pointer at +0x78 of the object the pointer at 0x57c9390 holds is
 * set, hands the object to FUN_00a51060 with it and clears the int at +0x254.
 * Class and method unknown; the fields' types beyond their widths are not
 * traced. */
struct Member057c9390_78; /* derived name */

struct Object057c9390 { /* derived name */
    u8 unknown0[0x78];
    Member057c9390_78 *unknown78;
};

extern Object057c9390 *D_57c9390;

struct Object00a2fc50 { /* derived name */
    u8 unknown0[0x254];
    int unknown254; /* +0x254 */
    int unknown258; /* +0x258 */
};

void FUN_00a51060(Member057c9390_78 *member, Object00a2fc50 *object); /* derived name */

void FUN_00a2fc50(Object00a2fc50 *self) /* derived name */
{
    if (self->unknown254 && self->unknown258 == 1 && D_57c9390->unknown78) {
        FUN_00a51060(D_57c9390->unknown78, self);
        self->unknown254 = 0;
    }
}
