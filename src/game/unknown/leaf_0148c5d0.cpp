/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes the object to FUN_013e8390, then stores its own
 * address at +0x518, +0x588, +0x5a8 and +0x618; slot 0 of the vtable at
 * 0x16d7c00 (its pointer at 0x16d7c10), stored by FUN_012bc3a0 and
 * FUN_012bd670, slot 1 FUN_014076a0. FUN_01406e10 and FUN_0148c5d0 are equal.
 * The fields' types beyond their widths and the callee's return type are not
 * traced. */
struct Object0148c5d0 { /* derived name */
    u8 unknown0[0x518];
    Object0148c5d0 *unknown518;
    u8 unknown520[0x68];
    Object0148c5d0 *unknown588;
    u8 unknown590[0x18];
    Object0148c5d0 *unknown5a8;
    u8 unknown5b0[0x68];
    Object0148c5d0 *unknown618;
};

void FUN_013e8390(Object0148c5d0 *object); /* derived name */

void FUN_0148c5d0(Object0148c5d0 *self) /* derived name */
{
    FUN_013e8390(self);
    self->unknown518 = self;
    self->unknown588 = self;
    self->unknown5a8 = self;
    self->unknown618 = self;
}
