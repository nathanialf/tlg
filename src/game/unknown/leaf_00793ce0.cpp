/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: resets the object at +0x1b0 through FUN_00214e10 (a tail call,
 * this advanced by 0x1b0); slot 15 of the primary vtable at 0x16ad610 (its pointer
 * at 0x16ad698), the vtable stored by FUN_00790a00 FUN_00790cb0, the only reference. Class and method
 * unknown. */
struct Object00214e10 { /* derived name */
    u8 unknown0
        [0x2c0]; /* size not traced: FUN_00214e10's highest access, a 16-byte store at +0x2b0, ends at +0x2c0 */
};

void FUN_00214e10(Object00214e10 *self);

struct Object00793ce0 { /* derived name */
    u8 unknown0[0x1b0];
    Object00214e10 unknown1b0;
};

void FUN_00793ce0(Object00793ce0 *self) /* derived name */
{
    FUN_00214e10(&self->unknown1b0);
}
