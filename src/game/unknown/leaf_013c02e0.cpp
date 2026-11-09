/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: stores its pointer argument at +0x18 and returns the pointer
 * it replaces; slot 148 of the vtable at 0x16bb0c0 (its pointer at 0x16bb570),
 * the vtable stored by FUN_00da4250 FUN_00ddbb60. The pointer's target is not
 * traced. Class and method unknown. */
struct Target013c02e0; /* derived name */

struct Object013c02e0 { /* derived name */
    u8 unknown0[0x18];
    Target013c02e0 *unknown18;
};

Target013c02e0 *FUN_013c02e0(Object013c02e0 *self, Target013c02e0 *value) /* derived name */
{
    Target013c02e0 *previous = self->unknown18;
    self->unknown18 = value;
    return previous;
}
