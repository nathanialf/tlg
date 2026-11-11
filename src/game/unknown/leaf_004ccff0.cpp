/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a virtual method (its address at 0x16aa468 in
 * .data.rel.ro) that, when the pointer at +0x28 is set and the one at +0x108
 * is still null, has FUN_002054d0 fill the slot at +0x108 from it (third
 * argument 0) and then clears bit 1 of the byte at +0x100 of the object the
 * slot now holds. FUN_002054d0 takes the slot by address and exchanges the
 * pointer into it. Class and method unknown; the fields' types beyond their
 * widths are not traced. */
struct Source004ccff0; /* derived name */

struct Target004ccff0 /* derived name */
{
    u8 unknown0[0x100];
    u8 flags100; /* +0x100 */
};

struct Object004ccff0 /* derived name */
{
    u8 unknown0[0x28];
    Source004ccff0 *unknown28; /* +0x28 */
    u8 unknown30[0xd8];
    Target004ccff0 *unknown108; /* +0x108 */
};

void FUN_002054d0(Target004ccff0 **slot, Source004ccff0 *source, int flag); /* derived name */

void FUN_004ccff0(Object004ccff0 *self) /* derived name */
{
    if (self->unknown28 && !self->unknown108) {
        FUN_002054d0(&self->unknown108, self->unknown28, 0);
        if (self->unknown108)
            self->unknown108->flags100 &= ~2;
    }
}
