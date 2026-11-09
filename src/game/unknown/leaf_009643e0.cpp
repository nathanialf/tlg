/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns whether the pointer at +0x98 is set; slot 10 of the
 * vtable at 0x16b1308 (its pointer at 0x16b1368), the vtable stored by
 * FUN_00961800 FUN_0137ed70, the only reference. Class and method unknown. */
struct Object009643e0 { /* derived name */
    u8 unknown0[0x98];
    void *unknown98; /* type not traced */
};

bool FUN_009643e0(const Object009643e0 *self) /* derived name */
{
    return self->unknown98 != 0;
}
