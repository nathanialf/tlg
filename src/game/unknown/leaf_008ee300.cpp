/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a virtual method (its address at 0x16b04b8 in
 * .data.rel.ro): when the int at +0x3c is set, hands the object to
 * FUN_008e1020 with the pointer at +0x80 of the object the pointer at
 * 0x57c9390 holds and clears the ints at +0x3c and +0x5c when that is set, and sets the
 * one at +0x58 to 1. Class and method unknown; the fields' types
 * beyond their widths are not traced. */
struct Member057c9390_80; /* derived name */

struct Object057c9390 { /* derived name */
    u8 unknown0[0x80];
    Member057c9390_80 *unknown80;
};

extern Object057c9390 *D_57c9390;

struct Object008ee300 { /* derived name */
    u8 unknown0[0x3c];
    int unknown3c; /* +0x3c */
    u8 unknown40[0x18];
    int unknown58; /* +0x58 */
    int unknown5c; /* +0x5c */
};

void FUN_008e1020(Member057c9390_80 *member, Object008ee300 *object); /* derived name */

void FUN_008ee300(Object008ee300 *self) /* derived name */
{
    if (self->unknown3c) {
        if (D_57c9390->unknown80) {
            FUN_008e1020(D_57c9390->unknown80, self);
            self->unknown3c = 0;
            self->unknown5c = 0;
        }
        self->unknown58 = 1;
    }
}
