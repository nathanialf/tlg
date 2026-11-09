/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: slot 7 of the vtable at 0x16bad98 (its pointer at 0x16bade0),
 * the vtable stored by FUN_00d86010 FUN_00d86290. It clears the pointer at
 * +0x220 that slot 6 (FUN_00d87ca0) sets; the argument the slot takes, as
 * slots 5 and 6 do, is unused. Class and method unknown. */
#include "tlg_types.h"

struct Object00d866c0; /* derived name: the pointee, not traced */

struct Object00d86010 { /* derived name */
    u8 unknown0[0x220];
    Object00d866c0 *
        unknown220; /* null after FUN_00d86010; read by FUN_00d866c0 (slot 1), which loads its 32-bit fields from +0x190; stored by FUN_00d87ca0, cleared by FUN_00d87cb0 */
};
struct Object00d87cc0; /* derived name */

void FUN_00d87cb0(Object00d86010 *self, Object00d87cc0 *) /* derived name */
{
    self->unknown220 = 0;
}
