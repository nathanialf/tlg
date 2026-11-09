/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the pointer at +0x7de8; slot 147 of the vtable at
 * 0x16bb0c0 (its pointer at 0x16bb568), the vtable stored by FUN_00da4250
 * FUN_00ddbb60. The pointer's target is not traced. Class and method unknown. */
struct Target013c02d0; /* derived name */

struct Object013c02d0 { /* derived name */
    u8 unknown0[0x7de8];
    Target013c02d0 *unknown7de8;
};

Target013c02d0 *FUN_013c02d0(const Object013c02d0 *self) /* derived name */
{
    return self->unknown7de8;
}
