/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_010532f0 with the pointer at +0x2a0 of the record
 * the pointer at +0x8 holds and the object, as a tail call; slot 4 of the
 * vtable at 0x16c1040 (its pointer at 0x16c1070). The types are not traced.
 * Class and method unknown. */
struct Target01061fc0; /* derived name */

struct Record01061fc0 { /* derived name */
    u8 unknown0[0x2a0];
    Target01061fc0 *unknown2a0;
};

struct Object01061fc0 { /* derived name */
    u8 unknown0[8];
    Record01061fc0 *unknown8;
};

void FUN_010532f0(Target01061fc0 *target, Object01061fc0 *object); /* derived name */

void FUN_01061fc0(Object01061fc0 *self) /* derived name */
{
    FUN_010532f0(self->unknown8->unknown2a0, self);
}
