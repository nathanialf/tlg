/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object016b64f8.h"

/* derived names: when the int at +0x180 is set, clears it, first handing
 * the object to FUN_00a50ca0 with the object at +0x78 of the object the
 * pointer at 0x57c9390 holds (and clearing the int at +0x80) when +0x80 is
 * set, +0x184 is clear and that object exists. Slot 8 of Object016b64f8
 * (its pointer at 0x16b6548); the destructor 0xb4b060 runs it first. */
struct Target00a50ca0; /* derived name */

struct Object057c9390 { /* derived name */
    u8 unknown0[0x78];
    Target00a50ca0 *unknown78; /* +0x78 */
};

extern Object057c9390 *D_57c9390;

void FUN_00a50ca0(Target00a50ca0 *target, Object016b64f8 *object); /* derived name */

void FUN_00b4b950(Object016b64f8 *self) /* derived name */
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
