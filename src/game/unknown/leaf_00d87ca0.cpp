/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: slot 6 of the vtable at 0x16bad98 (its pointer at 0x16badd8),
 * the vtable stored by FUN_00d86010 FUN_00d86290. It copies the pointer at
 * +0x28 of its argument to +0x220 of the object. The argument is the one slots
 * 5 to 7 take (FUN_00d87cc0, slot 5, reads the string handle at +0x50 of it);
 * its type and the pointee's are not traced. Class and method unknown. */
#include "tlg_types.h"

struct Object00d866c0; /* derived name: the pointee, not traced */

struct Object00d86010 { /* derived name */
    u8 unknown0[0x220];
    Object00d866c0 *
        unknown220; /* null after FUN_00d86010; read by FUN_00d866c0 (slot 1), which loads its 32-bit fields from +0x190; stored by FUN_00d87ca0, cleared by FUN_00d87cb0 */
};

struct Object00d87cc0 { /* derived name */
    u8 unknown0[0x28];
    Object00d866c0 *unknown28; /* copied to +0x220 of the object by FUN_00d87ca0 */
};

void FUN_00d87ca0(Object00d86010 *self, Object00d87cc0 *other) /* derived name */
{
    self->unknown220 = other->unknown28;
}
