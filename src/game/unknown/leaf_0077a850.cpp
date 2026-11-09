/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: resets the object at +0x120 through FUN_00214e10 (a tail call,
 * this advanced by 0x120); slot 15 of the primary vtable at 0x16ad228 (its pointer
 * at 0x16ad2b0), the vtable stored by FUN_007795c0 FUN_007796c0, the only reference. Class and method
 * unknown. */
struct Object00214e10 { /* derived name */
    u8 unknown0
        [0x2c0]; /* size not traced: FUN_00214e10's highest access, a 16-byte store at +0x2b0, ends at +0x2c0 */
};

void FUN_00214e10(Object00214e10 *self);

struct Object0077a850 { /* derived name */
    u8 unknown0[0x120];
    Object00214e10 unknown120;
};

void FUN_0077a850(Object0077a850 *self) /* derived name */
{
    FUN_00214e10(&self->unknown120);
}
