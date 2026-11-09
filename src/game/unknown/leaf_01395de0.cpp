/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores its pointer argument at +0x60, then calls FUN_009531c0
 * on the object as a tail call; slot 5 of the vtable at 0x16cf260 (its pointer
 * at 0x16cf298), the vtable stored by FUN_00b3de50 FUN_01396a10 FUN_01396b60.
 * FUN_009531c0 does not read its second argument register before its first
 * call. The pointer's target and the return type are not traced. Class and
 * method unknown. */
struct Target01395de0; /* derived name */

struct Object01395de0 { /* derived name */
    u8 unknown0[0x60];
    Target01395de0 *unknown60;
};

void FUN_009531c0(Object01395de0 *self); /* derived name */

void FUN_01395de0(Object01395de0 *self, Target01395de0 *value) /* derived name */
{
    self->unknown60 = value;
    FUN_009531c0(self);
}
