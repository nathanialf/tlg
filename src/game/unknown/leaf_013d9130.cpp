/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 2 of the vtables at 0x16bfc28 and 0x16bfcb8: calls FUN_013d9150
 * on the object, then sets the int at 0x70 to 0. Class and method unknown. */
struct Object013d9130 { /* derived name */
    u8 unknown0[0x70];
    int unknown70;
};

void FUN_013d9150(Object013d9130 *self); /* derived name */

void FUN_013d9130(Object013d9130 *self) /* derived name */
{
    FUN_013d9150(self);
    self->unknown70 = 0;
}
