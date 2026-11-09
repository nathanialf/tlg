/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00b3fc40 with the object and the pointer at +0x108,
 * as a tail call; slot 10 of the vtable at 0x16b5ae8 (its pointer at
 * 0x16b5b48), the vtable stored by FUN_00b3f8e0 (slot 5 FUN_009531c0).
 * FUN_00b3fc40 tests the pointer for null first. The pointee's type and the
 * return type are not traced. Class and method unknown. */
struct Target01396ff0; /* derived name */

struct Object013984d0 { /* derived name */
    u8 unknown0[0x108];
    Target01396ff0 *unknown108;
};

void FUN_00b3fc40(Object013984d0 *self, Target01396ff0 *value); /* derived name */

void FUN_01396ff0(Object013984d0 *self) /* derived name */
{
    FUN_00b3fc40(self, self->unknown108);
}
