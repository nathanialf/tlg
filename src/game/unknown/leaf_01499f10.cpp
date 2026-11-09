/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores its pointer argument at +0x130d0; slot 35 of the
 * vtable at 0x16c39b8 (its pointer at 0x16c3ae0), the vtable stored by
 * FUN_0130c660 FUN_0130dea0; slot 36 (FUN_01499f20) returns it. The pointer's
 * target is not traced. Class and method unknown. */
struct Target01499350; /* derived name */
struct Target01499f10; /* derived name */

struct Object01499350 { /* derived name */
    u8 unknown0[0x4670];
    Target01499350 *unknown4670; /* stored by FUN_01499350 */
    u8 unknown4678[0x130d0 - 0x4678];
    Target01499f10 *unknown130d0; /* stored by FUN_01499f10, returned by FUN_01499f20 */
};

void FUN_01499f10(Object01499350 *self, Target01499f10 *value) /* derived name */
{
    self->unknown130d0 = value;
}
