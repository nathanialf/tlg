/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: when the int at +0x180 is set, clears it, first handing
 * the object to FUN_00a50ca0 with the object at +0x78 of the object the
 * pointer at 0x57c9390 holds (and clearing the int at +0x80) when +0x80 is
 * set, +0x184 is clear and that object exists. Its pointer is at 0x16b6548
 * (a vtable without a row). Class and method unknown. */
struct Target00a50ca0; /* derived name */

struct Object057c9390 { /* derived name */
    u8 unknown0[0x78];
    Target00a50ca0 *unknown78; /* +0x78 */
};

extern Object057c9390 *D_57c9390;

struct Object00b4b950 { /* derived name */
    u8 unknown0[0x80];
    int unknown80; /* +0x80 */
    u8 unknown84[0x180 - 0x84];
    int unknown180; /* +0x180 */
    int unknown184; /* +0x184 */
};

void FUN_00a50ca0(Target00a50ca0 *target, Object00b4b950 *object); /* derived name */

void FUN_00b4b950(Object00b4b950 *self) /* derived name */
{
    if (self->unknown180) {
        if (self->unknown80 && !self->unknown184) {
            Target00a50ca0 *target = D_57c9390->unknown78;
            if (target) {
                FUN_00a50ca0(target, self);
                self->unknown80 = 0;
            }
        }
        self->unknown180 = 0;
    }
}
