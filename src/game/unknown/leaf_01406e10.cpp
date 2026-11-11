/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes the object to FUN_013e8390, then stores its own
 * address at +0x518, +0x588, +0x5a8 and +0x618; slot 0 of the vtable at
 * 0x16d5820 (its pointer at 0x16d5830), stored by FUN_010b0530 and
 * FUN_010b1800, slot 1 FUN_014076a0. FUN_01406e10 and FUN_0148c5d0 are equal.
 * The fields' types beyond their widths and the callee's return type are not
 * traced. */
struct Object01406e10 { /* derived name */
    u8 unknown0[0x518];
    Object01406e10 *unknown518;
    u8 unknown520[0x68];
    Object01406e10 *unknown588;
    u8 unknown590[0x18];
    Object01406e10 *unknown5a8;
    u8 unknown5b0[0x68];
    Object01406e10 *unknown618;
};

void FUN_013e8390(Object01406e10 *object); /* derived name */

void FUN_01406e10(Object01406e10 *self) /* derived name */
{
    FUN_013e8390(self);
    self->unknown518 = self;
    self->unknown588 = self;
    self->unknown5a8 = self;
    self->unknown618 = self;
}
